#include <iostream>
using namespace std;

class Temperature {
    private:
        double celsius;

    public:
        Temperature(double c = 0) : celsius(c) {}

        bool operator>(const Temperature& t) const { return celsius > t.celsius; }
        bool operator<(const Temperature& t) const { return celsius < t.celsius; }

        Temperature operator-() const { return Temperature(-celsius); }

        void display() const { cout << celsius << " °C"; }
};

int main() {
    Temperature t1(32.5), t2(25.0);

    cout << "t1 = "; 
    t1.display(); 
    cout << endl;

    cout << "t2 = "; 
    t2.display(); 
    cout << endl;

    cout << "t1 > t2 ? " << (t1 > t2 ? "true" : "false") << endl;
    cout << "t1 < t2 ? " << (t1 < t2 ? "true" : "false") << endl;

    Temperature t3 = -t1;
    cout << "-t1 = "; t3.display(); cout << endl;
    cout << "t1 still = "; 
    t1.display(); 
    cout << " (unchanged)" << endl;
    
    return 0;
}
