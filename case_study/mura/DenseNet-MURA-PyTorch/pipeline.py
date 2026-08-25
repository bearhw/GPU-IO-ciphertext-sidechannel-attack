import os
import struct
import pandas as pd
from tqdm import tqdm
import torch
from torchvision import transforms
from torch.utils.data import DataLoader, Dataset
from torchvision.datasets.folder import pil_loader


def va_to_gpa(va):
    page_size = 4096
    page_num  = va // page_size
    offset    = va % page_size
    with open('/proc/self/pagemap', 'rb') as f:
        f.seek(page_num * 8)
        entry = struct.unpack('Q', f.read(8))[0]
    present = (entry >> 63) & 1
    if not present:
        raise RuntimeError(f"page not present: VA=0x{va:x}")
    pfn = entry & ((1 << 55) - 1)
    return (pfn << 12) | offset


class InterceptNormalize(transforms.Normalize):
    """Print tensor GPA just before Normalize."""
    def forward(self, tensor):
        # tensor: (C, H, W) float32, contiguous
        tensor = tensor.contiguous()
        va     = tensor.data_ptr()
        n_bytes = tensor.numel() * tensor.element_size()
        n_pages = (n_bytes + 4095) // 4096
        gpa0 = va_to_gpa(va)
        gpa1 = va_to_gpa(va + (n_pages - 1) * 4096)
        print(f"[GPA] pid={os.getpid()}  shape={tuple(tensor.shape)}"
              f"  VA=0x{va:016x}"
              f"  GPA[0]=0x{gpa0:016x}  GPA[last]=0x{gpa1:016x}"
              f"  pages={n_pages}", flush=True)
        return super().forward(tensor)

data_cat = ['train', 'valid'] # data categories

def get_study_level_data(study_type):
    """
    Returns a dict, with keys 'train' and 'valid' and respective values as study level dataframes, 
    these dataframes contain three columns 'Path', 'Count', 'Label'
    Args:
        study_type (string): one of the seven study type folder names in 'train/valid/test' dataset 
    """
    study_data = {}
    study_label = {'positive': 1, 'negative': 0}
    for phase in data_cat:
        BASE_DIR = 'MURA-v1.0/%s/%s/' % (phase, study_type)
        patients = list(os.walk(BASE_DIR))[0][1] # list of patient folder names
        study_data[phase] = pd.DataFrame(columns=['Path', 'Count', 'Label'])
        i = 0
        for patient in tqdm(patients): # for each patient folder
            for study in os.listdir(BASE_DIR + patient): # for each study in that patient folder
                label = study_label[study.split('_')[1]] # get label 0 or 1
                path = BASE_DIR + patient + '/' + study + '/' # path to this study
                study_data[phase].loc[i] = [path, len(os.listdir(path)), label] # add new row
                i+=1
    return study_data

class ImageDataset(Dataset):
    """training dataset."""

    def __init__(self, df, transform=None):
        """
        Args:
            df (pd.DataFrame): a pandas DataFrame with image path and labels.
            transform (callable, optional): Optional transform to be applied
                on a sample.
        """
        self.df = df
        self.transform = transform

    def __len__(self):
        return len(self.df)

    def __getitem__(self, idx):
        study_path = self.df.iloc[idx, 0]
        count = self.df.iloc[idx, 1]
        images = []
        for i in range(count):
            image = pil_loader(study_path + 'image%s.png' % (i+1))
            images.append(self.transform(image))
        images = torch.stack(images)
        label = self.df.iloc[idx, 2]
        sample = {'images': images, 'label': label}
        return sample

def get_dataloaders(data, batch_size=8, study_level=False, num_workers=4):
    '''
    Returns dataloader pipeline with data augmentation
    '''
    data_transforms = {
        'train': transforms.Compose([
                transforms.Resize((224, 224)),
                transforms.RandomHorizontalFlip(),
                transforms.RandomRotation(10),
                transforms.ToTensor(),
                InterceptNormalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225]),
        ]),
        'valid': transforms.Compose([
            transforms.Resize((224, 224)),
            transforms.ToTensor(),
            InterceptNormalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225]),
        ]),
    }
    image_datasets = {x: ImageDataset(data[x], transform=data_transforms[x]) for x in data_cat}
    dataloaders = {x: DataLoader(image_datasets[x], batch_size=batch_size, shuffle=True, num_workers=num_workers) for x in data_cat}
    return dataloaders

if __name__=='main':
    pass
