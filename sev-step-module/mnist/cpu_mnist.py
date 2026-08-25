"""CPU-only MNIST training script."""
import time
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader
from torchvision import datasets, transforms

torch.manual_seed(0)
DEVICE = torch.device("cpu")


class Net(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 32, 3, 1)
        self.conv2 = nn.Conv2d(32, 64, 3, 1)
        self.fc1 = nn.Linear(9216, 128)
        self.fc2 = nn.Linear(128, 10)

    def forward(self, x):
        x = F.relu(self.conv1(x))
        x = F.max_pool2d(F.relu(self.conv2(x)), 2)
        x = torch.flatten(x, 1)
        x = F.relu(self.fc1(x))
        return self.fc2(x)


def main():
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.1307,), (0.3081,)),
    ])
    train_ds = datasets.MNIST("./data", train=True, download=True, transform=transform)
    test_ds = datasets.MNIST("./data", train=False, download=True, transform=transform)
    train_loader = DataLoader(train_ds, batch_size=64, shuffle=True)
    test_loader = DataLoader(test_ds, batch_size=1000)

    model = Net().to(DEVICE)
    optimizer = torch.optim.Adadelta(model.parameters(), lr=1.0)

    for epoch in range(1, 3):
        model.train()
        for batch_idx, (data, target) in enumerate(train_loader):
            data, target = data.to(DEVICE), target.to(DEVICE)
            print(f"[TS] epoch{epoch}/batch{batch_idx}/input: write_done_realtime_ns={time.time_ns()}", flush=True)
            optimizer.zero_grad()
            loss = F.cross_entropy(model(data), target)
            loss.backward()
            optimizer.step()
            if batch_idx % 100 == 0:
                print(f"Epoch {epoch} [{batch_idx * len(data)}/{len(train_ds)}] loss={loss.item():.4f}")

        model.eval()
        correct = 0
        with torch.no_grad():
            for data, target in test_loader:
                data, target = data.to(DEVICE), target.to(DEVICE)
                pred = model(data).argmax(dim=1)
                correct += pred.eq(target).sum().item()
        print(f"Epoch {epoch} test accuracy: {100. * correct / len(test_ds):.2f}%")


if __name__ == "__main__":
    main()
