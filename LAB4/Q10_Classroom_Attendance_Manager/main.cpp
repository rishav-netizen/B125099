#include <iostream>
#include <string>

using namespace std;

class AttendanceManager;

class Classroom {
    private:
        string className;
        int totalStudents;
        int presentStudents;
        bool attendanceStatus;

    public:
        Classroom() {}
        Classroom(string name, int total) {
            className = name;
            totalStudents = total;
            presentStudents = 0;
            attendanceStatus = false;
        }

        void Input() {
            cout << "Enter class name: ";
            getline(cin, className);

            cout << "Enter total students: ";
            cin >> totalStudents;

            cout << "Enter present students: ";
            cin >> presentStudents;
            
            while (presentStudents > totalStudents)
            {
                cout << "Invalid Input\nEnter present students: ";
                cin >> presentStudents;
            }
            

            cout << "Enter attendance status (1 for Completed, 0 for Not Completed): ";
            cin >> attendanceStatus;
        }

        friend class AttendanceManager;
};

class AttendanceManager {
    public:
        void displayInfo(Classroom &c) {
            cout << "\n--CLASS DETAILS--\n";
            cout << "Class: " << c.className << endl;
            cout << "Total Students: " << c.totalStudents << endl;
            cout << "Present Students: " << c.presentStudents << endl;
            cout << "Attendance: "
                 << (c.attendanceStatus ? "Completed" : "Not Completed")
                 << endl;
        }

        void updatePresent(Classroom &c, int present) {
            if (present >= 0 && present <= c.totalStudents)
                c.presentStudents = present;
        }

        void completeAttendance(Classroom &c) {
            c.attendanceStatus = true;
        }

        void displayStatus(Classroom &c) {
            cout << "Attendance Status: "
                 << (c.attendanceStatus ? "Completed" : "Not Completed")
                 << endl;
        }

        void calculateAbsent(Classroom &c) {
            int absent = c.totalStudents - c.presentStudents;
            cout << "Absent Students: " << absent << endl;
        }
};

int main() {
    Classroom c;
    AttendanceManager manager;

    c.Input();

    manager.displayInfo(c);
    manager.calculateAbsent(c);
    manager.displayStatus(c);

    return 0;
}