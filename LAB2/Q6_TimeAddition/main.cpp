#include <iostream>

using namespace std;

// Made class for Time
class Time
{
private:
    int hours, minutes;

public:
    // Taking users input
    void inputTime()
    {
        cout << "Enter Hours: ";
        cin >> hours;

        cout << "Enter Minutes: ";
        cin >> minutes;
    }

    void addTime(Time t)
    {
        hours += t.hours;
        minutes += t.minutes;

        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

    void displayTime()
    {
        cout << "Resulting Time is: " << hours << " hr " << minutes << " min" << endl;
    }
};

int main()
{
    // creating Time objects
    Time t1, t2;

    // inputting two times
    cout << "Enter First Time\n";
    t1.inputTime();

    cout << "\nEnter Second Time\n";
    t2.inputTime();

    // adding them
    t1.addTime(t2);

    // displaying them
    cout << "\n";
    t1.displayTime();

    return 0; // exiting code
}