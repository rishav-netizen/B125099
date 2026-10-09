#include <iostream>
#include <cstdlib> 
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

class Fraction {
    private:
        int numerator;
        int denominator;

        void simplify() {
            if (denominator < 0) { //? to keep denominator positive
                numerator = -numerator;
                denominator = -denominator;
            }
            int g = gcd(abs(numerator), abs(denominator));
            numerator /= g;
            denominator /= g;
        }

    public:
        Fraction(int n = 0, int d = 1){
            numerator = n;
            denominator = d;
            if (denominator == 0) {
                cout << "Denominator cannot be zero!\n";
                exit(0);
            }
            simplify();
        }

        Fraction operator+(const Fraction& f) const {
            return Fraction(numerator * f.denominator + f.numerator * denominator,
                            denominator * f.denominator);
        }

        Fraction operator-(const Fraction& f) const {
            return Fraction(numerator * f.denominator - f.numerator * denominator,
                            denominator * f.denominator);
        }

        void display() const {
            cout << numerator << "/" << denominator;
        }
};

int main() {
    Fraction f1(3, 4), f2(8, 6);

    cout << "f1 = "; 
    f1.display(); 
    cout << endl;
    cout << "f2 = "; 
    f2.display(); 
    cout << endl;

    Fraction sum = f1 + f2;
    cout << "f1 + f2 = "; 
    sum.display(); 
    cout << endl;

    Fraction diff = f1 - f2;
    cout << "f1 - f2 = "; 
    diff.display(); 
    cout << endl;

    cout << "Originals unchanged: f1 = "; f1.display();
    cout << ", f2 = "; 
    f2.display(); 
    cout << endl;

    return 0;
}
