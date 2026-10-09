#include <iostream>
using namespace std;

class Date {
    private:
        int day, month, year;

    public:
        Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

        bool operator==(const Date& dt) const {
            return day == dt.day && month == dt.month && year == dt.year;
        }

        bool operator!=(const Date& dt) const {
            return !(*this == dt);
        }

        void display() const {
            cout << day << "/" << month << "/" << year;
        }
};

int main() {
    Date d1(9, 10, 2026), d2(9, 10, 2026), d3(10, 10, 2026);

    cout << "d1 = "; d1.display(); cout << endl;
    cout << "d2 = "; d2.display(); cout << endl;
    cout << "d3 = "; d3.display(); cout << endl;

    cout << "d1 == d2 ? " << (d1 == d2 ? "true" : "false") << endl;
    cout << "d1 != d2 ? " << (d1 != d2 ? "true" : "false") << endl;
    cout << "d1 == d3 ? " << (d1 == d3 ? "true" : "false") << endl;
    cout << "d1 != d3 ? " << (d1 != d3 ? "true" : "false") << endl;
    return 0;
}
