from pathlib import Path
baseProblem = 1
finalProblem = 10
for i in range(baseProblem, finalProblem + 1):
    folder = Path(f"Q{i}")
    folder.mkdir(exist_ok=True)

    (folder / "main.cpp").touch(exist_ok=True)
    (folder / "output.txt").touch(exist_ok=True)