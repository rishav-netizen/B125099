#include <iostream>
#include <string>
using namespace std;

class PrinterManager;

class Printer {
private:
    string printerName;
    int pagesPrinted;
    int inkLevel;
    bool powerStatus;

public:
    Printer(string name, int pages, int ink, bool power) {
        printerName = name;
        pagesPrinted = pages;
        inkLevel = ink;
        powerStatus = power;
    }

    friend class PrinterManager;
};

class PrinterManager {
public:
    void displayInfo(Printer &p) {
        cout << "Printer: " << p.printerName << endl;
        cout << "Pages Printed: " << p.pagesPrinted << endl;
        cout << "Ink Level: " << p.inkLevel << "%" << endl;
        cout << "Power: " << (p.powerStatus ? "ON" : "OFF") << endl;
    }

    void turnOn(Printer &p) {
        p.powerStatus = true;
    }

    void turnOff(Printer &p) {
        p.powerStatus = false;
    }

    void checkInk(Printer &p) {
        cout << "Ink Level: " << p.inkLevel << "%" << endl;
    }

    void resetPages(Printer &p) {
        p.pagesPrinted = 0;
    }
};

int main() {
    Printer p("HP LaserJet", 250, 75, false);
    PrinterManager manager;

    manager.displayInfo(p);

    manager.turnOn(p);
    manager.resetPages(p);

    cout << "\nAfter Changes:\n";
    manager.displayInfo(p);

    manager.checkInk(p);

    return 0;
}