#include <iostream>
#include <string>

using namespace std;

class MuseumManager;

class Exhibit {
    private:
        string exhibitName;
        int exhibitID;
        int visitorCount;
        bool displayStatus;

    public:
        void Input() {
            cout << "Enter exhibit name: ";
            getline(cin, exhibitName);

            cout << "Enter exhibit ID: ";
            cin >> exhibitID;

            cout << "Enter visitor count: ";
            cin >> visitorCount;

            cout << "Enter display status (1 for Open, 0 for Closed): ";
            cin >> displayStatus;
        }
        Exhibit()
        {

        }

        Exhibit(string name, int id) {
            exhibitName = name;
            exhibitID = id;
            visitorCount = 0;
            displayStatus = false;
        }

        friend class MuseumManager;
};

class MuseumManager {
public:
    void displayInfo(Exhibit &e) {
        cout << "\nData Regarding Exibit\nExhibit: " << e.exhibitName << endl;
        cout << "Exhibit ID: " << e.exhibitID << endl;
        cout << "Visitors: " << e.visitorCount << endl;
        cout << "Status: " << (e.displayStatus ? "Open" : "Closed") << endl;
    }

    void addVisitors(Exhibit &e, int count) {
        e.visitorCount += count;
    }

    void resetVisitors(Exhibit &e) {
        e.visitorCount = 0;
    }

    void openExhibit(Exhibit &e) {
        e.displayStatus = true;
    }

    void closeExhibit(Exhibit &e) {
        e.displayStatus = false;
    }

    void checkStatus(Exhibit &e) {

        cout << (e.displayStatus ? "Exhibit is Open" : "Exhibit is Closed")
             << endl;
    }
};

int main() {
    Exhibit e;
    e.Input();

    MuseumManager manager;

    manager.openExhibit(e);
    manager.addVisitors(e, 50);

    manager.displayInfo(e);
    manager.checkStatus(e);

    return 0;
}