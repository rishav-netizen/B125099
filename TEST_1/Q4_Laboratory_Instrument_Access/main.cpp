#include <iostream>
#include <string>

using namespace std;

class LabSupervisor;   

class Instrument 
{
    private:
        int id;
        string name;
        int accessLevel;

    public:
        Instrument(int i, string n, int level)
        {
            id = i;
            name = n;
            accessLevel = level;
        }

        Instrument()
        {
            id = 0;
            accessLevel = 0;
        }

        void display()
        {
            cout << "ID: " << id
                << "\nName: " << name
                << "\nAccess Level: " << accessLevel << endl;
        }

        void input()
        {
            cout << "Enter instrument ID: ";
            cin >> id;

            cout << "Enter instrument name: ";
            getline(cin >> ws, name);

            cout << "Enter access level: ";
            cin >> accessLevel;
        }

        friend class LabSupervisor;
};

class LabSupervisor 
{
    public:
        void checkAccess(Instrument *i)
        {
            cout << "Current access level: "
                << i->accessLevel << endl;
        }

        void modifyAccess(Instrument *i, int newLevel)
        {
            i->accessLevel = newLevel;
        }
};

int main() 
{
    Instrument *instrument = new Instrument;
    
    LabSupervisor supervisor;
    instrument->input();
    
    cout << "\nThe data entered is: \n";
    instrument->display();

    supervisor.checkAccess(instrument);

    int level;
    cout << "\nEnter the modified access level: ";
    cin >> level;
    supervisor.modifyAccess(instrument, level);

    cout << "\nAfter modification:\n";
    instrument->display();

    delete instrument;
    instrument = nullptr;
    return 0;
}