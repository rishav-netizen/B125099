#include <iostream>
#include <string>

using namespace std;

class PrinterManager;

class Printer {
    private:
        string printerName;
        int pagesPrinted;
        double inkLevel;
        bool powerStatus;

    public:
        Printer() {}

        void Input() {
            cout << "Enter printer name: ";
            getline(cin, printerName);

            cout << "Enter pages printed: ";
            cin >> pagesPrinted;

            cout << "Enter ink level (%): ";
            cin >> inkLevel;

            cout << "Enter power status (1 for ON, 0 for OFF): ";
            cin >> powerStatus;
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

        void reduceInk(Printer &p) {
            p.inkLevel -= 0.5*p.pagesPrinted;
        }
};

int main() {
    Printer p;
    PrinterManager manager;

    p.Input();

    cout << "\nPrinter Information:\n";
    manager.displayInfo(p);
    manager.reduceInk(p);
    manager.resetPages(p);
    manager.turnOff(p);

    cout << "\nAfter Changes:\n";
    manager.displayInfo(p);

    return 0;
}