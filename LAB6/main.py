import os
from pathlib import Path

folders = [
    "Q01_Fraction_Calculator",
    "Q02_Time_Duration_Calculator",
    "Q03_Book_Price_Ranking",
    "Q04_Unary_Operator",
    "Q05_Score_Tracker",
    "Q06_Date_Equality",
    "Q07_Inventory_Combination",
    "Q08_Temperature_Comparison",
    "Q09_Matrix_Addition",
    "Q10_Shopping_Bill_Operations"
]

for folder_name in folders:
    folder = Path(folder_name)
    folder.mkdir(exist_ok=True)
    (folder / "main.cpp").touch(exist_ok=True)
    (folder / "output.txt").touch(exist_ok=True)
