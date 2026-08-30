import os
from pathlib import Path

folders = [
    "Q1_Distance_Converter",
    "Q2_Area_Calculator",
    "Q3_Character_Analyzer",
    "Q4_Array_Processing",
    "Q5_Swap_Values",
    "Q6_String_Information",
    "Q7_Nearest_Value",
    "Q8_Update_Array_Elements",
    "Q9_Data_Inspection_Using_Pointers",
    "Q10_Result_Evaluator"
]

for folder_name in folders:
    folder = Path(folder_name)
    folder.mkdir(exist_ok=True)
    (folder / "main.cpp").touch(exist_ok=True)
    (folder / "output.txt").touch(exist_ok=True)
