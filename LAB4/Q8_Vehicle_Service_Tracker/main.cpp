#include <iostream>
#include <string>
using namespace std;

class ServiceManager;

class VehicleService {
    private:
        string vehicleNumber;
        string ownerName;
        bool serviceDue;
        int lastServiceKm;

    public:
        VehicleService(string number, string owner, bool due, int km) {
            vehicleNumber = number;
            ownerName = owner;
            serviceDue = due;
            lastServiceKm = km;
        }

        friend class ServiceManager;
};

class ServiceManager {
    public:
        void displayInfo(VehicleService &v) {
            cout << "Vehicle Number: " << v.vehicleNumber << endl;
            cout << "Owner: " << v.ownerName << endl;
            cout << "Last Service: " << v.lastServiceKm << " km" << endl;
            cout << "Service Due: " << (v.serviceDue ? "Yes" : "No") << endl;
        }

        void completeService(VehicleService &v) {
            v.serviceDue = false;
        }

        void updateKm(VehicleService &v, int km) {
            v.lastServiceKm = km;
        }

        void checkService(VehicleService &v) {
            if (v.serviceDue)
                cout << "Vehicle requires servicing." << endl;
            else
                cout << "Vehicle does not require servicing." << endl;
        }
};

int main() {
    VehicleService v("OD02AB1234", "Rishav", true, 15000);
    ServiceManager manager;

    manager.displayInfo(v);
    manager.checkService(v);

    manager.completeService(v);

    cout << "\nAfter Service:\n";
    manager.checkService(v);

    return 0;
}