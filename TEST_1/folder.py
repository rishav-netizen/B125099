import os
from pathlib import Path

folders = [
    "Q1_Smart_Locker_Allocation",
    "Q2_Drone_Battery_Monitor",
    "Q3_Movie_Queue_Display",
    "Q4_Laboratory_Instrument_Access",
    "Q5_E-Wallet_Transaction_Record"
]

for folder_name in folders:
    folder = Path(folder_name)
    folder.mkdir(exist_ok=True)
    (folder / "main.cpp").touch(exist_ok=True)
    (folder / "output.txt").touch(exist_ok=True)
