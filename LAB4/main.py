from pathlib import Path
initial = 1
final = 10
for i in range(initial, final + 1):
    folder = Path(f"Q{i}")
    folder.mkdir(exist_ok=True)

    (folder / "main.cpp").touch(exist_ok=True)
    (folder / "output.txt").touch(exist_ok=True)