#include <iostream>
#include <cctype>

using namespace std;

class EventParticipant {
    private:
        string participantName;
        int age;
        string registrationStatus;

    public:
        EventParticipant()
        {

        }

        EventParticipant(string name, int a, string status) {
            participantName = name;
            age = a;
            registrationStatus = status;
        }

        void Input() {
            cout << "Enter participant name: ";
            getline(cin, participantName);

            cout << "Enter age: ";
            cin >> age;
            cin.ignore(); 

            cout << "Enter registration status: ";
            getline(cin, registrationStatus);
        }

        friend void verifyParticipant(EventParticipant p);
};

void verifyParticipant(EventParticipant p) {
    cout << "\nParticipant Details are as follows:\n";
    cout << "\nParticipant: " << p.participantName << endl;
    cout << "Age: " << p.age << endl;

    // modifies each char in the string of registration status to lowercase and then capitalizes first
    for (char &c : p.registrationStatus) {
        c = tolower(c);
    }   
    p.registrationStatus[0] = toupper(p.registrationStatus[0]);

    cout << "Registration Status: " << p.registrationStatus << endl;

    if (p.age >= 18 && p.registrationStatus == "Active")
        cout << "Eligible" << endl;
    else
        cout << "Not Eligible" << endl;
}

int main() {
    EventParticipant p;

    p.Input();
    verifyParticipant(p);

    return 0;
}