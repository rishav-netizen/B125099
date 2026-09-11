#include <iostream>

using namespace std;

class Drone
{
    private:
        int id;
        float battery;
        float flightHours;

    public:
        Drone(int i, float b, float h)
        {
            id = i;
            battery = b;
            flightHours = h;
        }

        Drone()
        {
            id = 0;
            battery = 0;
            flightHours = 0;
        }

        // Update only battery
        void update(float b)
        {
            battery = b;
        }

        // Update battery and flight hours
        void update(float b, float h)
        {
            battery = b;
            flightHours = h;
        }

        void display()
        {
            cout << "Drone ID: " << id
                << " Battery: " << battery << "%"
                << " Flight Hours: " << flightHours << endl;
        }
        
        void droneInput()
        {
            cout << "Enter the drone id: ";
            cin >> id;
            cout << "Enter the drone battery(%): ";
            cin >> battery;
            while (battery < 0 || battery > 100)
            {
                cout << "Invalid input try again: ";
                cin >> battery;
            }
            cout << "Enter the flight hours: ";
            cin >> flightHours;
            while (flightHours < 0)
            {
                cout << "Invalid input try again: ";
                cin >> flightHours;
            }
            cout << endl;
        }

        friend void compareBattery(Drone, Drone);
};

int main()
{
    Drone *d1 = new Drone;
    cout << "Enter data for drone 1: \n";
    d1->droneInput();
    
    Drone *d2 = new Drone;
    cout << "Enter data for drone 2: \n";
    d2->droneInput();

    float ub1;
    cout << "Update drone 1 battery to: ";
    cin >> ub1;
    d1->update(ub1);

    float ub2, uf2;
    cout << "\nUpdate drone 2 battery and flight hours: ";
    cin >> ub2 >> uf2;
    d2->update(ub2, uf2);

    cout << endl;
    d1->display();
    cout << endl;
    d2->display();
    cout << endl;

    compareBattery(*d1, *d2);

    delete d1;
    d1 = nullptr;
    delete d2;
    d2 = nullptr;

    return 0;
}

void compareBattery(Drone d1, Drone d2)
{
    if (d1.battery > d2.battery)
    {
        cout << "Drone with ID: " << d1.id << " has higher battery.\n";
    }
    else if (d2.battery > d1.battery)
    {
        cout << "Drone with ID: " << d2.id << " has higher battery.\n";
    }
    else
    {
        cout << "Both drones have equal battery.\n";
    }
}