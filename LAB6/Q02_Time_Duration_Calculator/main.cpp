#include <iostream>
using namespace std;

class Duration {
    private:
        int hours, minutes;

        void normalize() {
            if (minutes >= 60) {
                hours += minutes / 60;
                minutes %= 60;
            }
        }

    public:
        Duration(int h = 0, int m = 0) : hours(h), minutes(m) { normalize(); }

        Duration operator+(const Duration& d) const {
            return Duration(hours + d.hours, minutes + d.minutes);
        }

        void display() const {
            cout << hours << "h " << minutes << "m";
        }
};

int main() {
    Duration d1(2, 45), d2(1, 30);

    cout << "d1 = "; 
    d1.display();
    cout << endl;
    
    cout << "d2 = "; 
    d2.display();
    cout << endl;
    
    Duration d3 = d1 + d2;
    cout << "d1 + d2 = ";
    d3.display();
    cout << endl;
    return 0;
}
