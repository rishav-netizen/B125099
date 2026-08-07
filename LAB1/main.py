#!/usr/bin/env python3

import os
import subprocess
from pathlib import Path

# -----------------------------
# Sample inputs for each question
# -----------------------------
TEST_INPUTS = {
    "01_ArrayStatistics": "5\n5\n10 20 30 40 50\n",

    "02_ReverseArray": "5\n5\n1 2 3 4 5\n",

    "03_LinearSearch": "5\n5\n10 20 30 40 50\n30\n",

    "04_SwapUsingPointers": "10\n20\n",

    "05_SumOfArrayUsingPointerArithmetic": "5\n5\n1 2 3 4 5\n",

    "06_StudentStruct":
        "Alice\n101\n90\n"
        "Bob\n102\n85\n"
        "Charlie\n103\n92\n"
        "David\n104\n88\n"
        "Eva\n105\n95\n",

    "07_StudentAnalysis":
        "Alice\n101\n90\n"
        "Bob\n102\n85\n"
        "Charlie\n103\n92\n"
        "David\n104\n88\n"
        "Eva\n105\n95\n",

    "08_DynamicMemoryAllocation":
        "5\n1 2 3 4 5\n",

    "09_PointerToStruct":
        "101\nAlice Johnson\n95.5\n",

    "10_DynamicStudentRecords":
        "3\n"
        "101\nAlice Johnson\n91.5\n"
        "102\nBob Smith\n87.0\n"
        "103\nCharlie Brown\n95.5\n",
}

ROOT = Path(__file__).parent.resolve()

for folder in sorted(ROOT.iterdir()):
    if not folder.is_dir():
        continue

    cpp_file = folder / "main.cpp"
    c_file = folder / "main.c"

    if cpp_file.exists():
        source = cpp_file
        compiler = ["g++", "-std=c++17"]
    elif c_file.exists():
        source = c_file
        compiler = ["gcc", "-std=c17"]
    else:
        continue

    executable = folder / "program"
    output_file = folder / "output.txt"
    error_file = folder / "compile_error.txt"

    if error_file.exists():
        error_file.unlink()

    compile_result = subprocess.run(
        compiler + [str(source), "-o", str(executable)],
        capture_output=True,
        text=True,
    )

    if compile_result.returncode != 0:
        error_file.write_text(compile_result.stderr)
        print(f"❌ Compilation failed: {folder.name}")
        continue

    try:
        run_result = subprocess.run(
            [str(executable)],
            input=TEST_INPUTS.get(folder.name, ""),
            capture_output=True,
            text=True,
            timeout=5,
        )

        input_used = TEST_INPUTS.get(folder.name, "")

        formatted_output = (
            "===== INPUT =====\n"
            f"{input_used}\n"
            "===== OUTPUT =====\n"
            f"{run_result.stdout}"
        )

        output_file.write_text(formatted_output)

        print(f"✅ {folder.name}")

    except subprocess.TimeoutExpired:
        output_file.write_text("Program timed out.\n")
        print(f"⏱️ {folder.name}")

    finally:
        if executable.exists():
            executable.unlink()