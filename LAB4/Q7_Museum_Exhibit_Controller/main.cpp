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
        cout << "Exhibit: " << e.exhibitName << endl;
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
    Exhibit e("Ancient Art", 101);
    MuseumManager manager;

    manager.openExhibit(e);
    manager.addVisitors(e, 50);

    manager.displayInfo(e);
    manager.checkStatus(e);

    return 0;
}