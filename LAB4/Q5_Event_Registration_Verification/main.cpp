#include <iostream>
#include <string>
using namespace std;

class EventParticipant {
private:
    string participantName;
    int age;
    string registrationStatus;

public:
    EventParticipant(string name, int a, string status) {
        participantName = name;
        age = a;
        registrationStatus = status;
    }

    friend void verifyParticipant(EventParticipant p);
};

void verifyParticipant(EventParticipant p) {
    cout << "Participant: " << p.participantName << endl;
    cout << "Age: " << p.age << endl;
    cout << "Registration Status: " << p.registrationStatus << endl;

    if (p.age >= 18 && p.registrationStatus == "Active")
        cout << "Eligible" << endl;
    else
        cout << "Not Eligible" << endl;
}

int main() {
    EventParticipant p("Rishav", 19, "Active");
    verifyParticipant(p);

    return 0;
}