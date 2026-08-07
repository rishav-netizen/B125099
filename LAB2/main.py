from pathlib import Path
import subprocess
import os

ROOT = Path(__file__).parent

# Change this if you use a different compiler (e.g. g++-15)
COMPILER = "g++"

# Sample inputs for each question
TEST_INPUTS = {
    "Q1_CarInformationSystem": "OD05AB1234\n2024\nToyota\n",
    "Q2_SquareCalculator": "5\n",
    "Q3_TemperatureConverter": "37\n",
    "Q4_HotelRoomBooking": "Rishav Kumar\n101\n3\n",
    "Q5_MobileRechargeSystem": "Rishav Kumar\n9876543210\n200\n100\n149\n",
    "Q6_TimeAddition": "2\n45\n1\n30\n",
    "Q7_MovieTicketBooking": "Interstellar\n250\n3\n",
    "Q8_HostelFeeManagement": "Rishav Kumar\n123\n5000\n6\nY\n",
    "Q9_CricketScoreAnalyzer": "Virat Kohli\n25\n1500\n",
    "Q10_WaterBillCalculator": "1001\nRishav Kumar\n1200\n",
}

for folder in sorted(ROOT.iterdir()):
    if not folder.is_dir():
        continue

    # Find the first .cpp file in the folder
    cpp_files = list(folder.glob("*.cpp"))
    if not cpp_files:
        continue

    cpp = cpp_files[0]
    exe = folder / "program"

    print(f"Processing {folder.name}...")

    # Compile
    compile_result = subprocess.run(
        [COMPILER, str(cpp), "-o", str(exe)],
        capture_output=True,
        text=True,
    )

    if compile_result.returncode != 0:
        print(f"❌ Compilation failed for {folder.name}")

        with open(folder / "compile_error.txt", "w") as f:
            f.write(compile_result.stderr)

        continue

    # Run
    try:
        run_result = subprocess.run(
            [str(exe)],
            input=TEST_INPUTS.get(folder.name, ""),
            capture_output=True,
            text=True,
            timeout=10,
        )

        with open(folder / "output.txt", "w") as f:
            f.write(run_result.stdout)

            if run_result.stderr:
                f.write("\n\n--- STDERR ---\n")
                f.write(run_result.stderr)

        print(f"✅ output.txt created for {folder.name}")

    except subprocess.TimeoutExpired:
        print(f"⏰ {folder.name} timed out.")

    # Delete executable
    if exe.exists():
        os.remove(exe)

print("\nDone!")