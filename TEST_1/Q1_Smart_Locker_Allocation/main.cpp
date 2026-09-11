#include <iostream>
#include <cstring>

using namespace std;

class Locker
{
    private: 
        int lockerNo;
        bool occupied;
        char *code;

    public:
        Locker()
        {
            code = new char[50];
            strcpy(code, "");
            lockerNo = 0;
            occupied = false;
        }

        void setLocker(int n, bool status)
        {
            lockerNo = n;
            occupied = status;
        }

        // Complete code
        void setCode(const char *newCode)
        {
            strcpy(code, newCode);
        }

        // Change code at specified position
        void setCode(int pos, char ch)
        {
            code[pos] = ch;
        }

        void display()
        {
            cout << "Locker: " << lockerNo
                << " Occupied: " << occupied
                << " Code: " << code << endl;
        }

        ~Locker()
        {
            delete[] code;
            code = nullptr;
        }
};

int main()
{
    int n;
    cout << "Enter number of lockers: ";
    cin >> n;
    
    Locker *lockers = new Locker[n];

    char tempCode[50];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter code for locker " << (i + 1) << ": ";
        cin >> tempCode;
        (lockers + i)->setLocker(i + 1, true);
        (lockers + i)->setCode(tempCode);
    }

    cout << "\nLocker Details:\n";
    for (int i = 0; i < n; i++)
    {
        (lockers + i)->display();
    }

    int pos;
    char ch;
    cout << "\nEnter position and new character to modify locker 1 code: ";
    cin >> pos >> ch;

    // Pointer access
    Locker *p = lockers;
    p->setCode(pos, ch);

    cout << "\nAfter modification:\n";
    for (int i = 0; i < n; i++)
    {
        (lockers + i)->display();
    }

    delete[] lockers;
    lockers = nullptr;
    return 0;
}
