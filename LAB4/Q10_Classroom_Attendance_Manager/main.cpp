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
    Classroom(string name, int total) {
        className = name;
        totalStudents = total;
        presentStudents = 0;
        attendanceStatus = false;
    }

    friend class AttendanceManager;
};

class AttendanceManager {
public:
    void displayInfo(Classroom &c) {
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
    Classroom c("CSE B1", 60);
    AttendanceManager manager;

    manager.updatePresent(c, 52);
    manager.completeAttendance(c);

    manager.displayInfo(c);
    manager.calculateAbsent(c);
    manager.displayStatus(c);

    return 0;
}