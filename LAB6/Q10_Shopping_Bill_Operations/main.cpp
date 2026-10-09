#include <iostream>
using namespace std;

class Bill {
    private:
        int items;
        double amount;

    public:
        Bill(int i = 0, double amt = 0) : items(i), amount(amt) {}

        Bill operator+(const Bill& b) const {
            return Bill(items + b.items, amount + b.amount);
        }

        bool operator>(const Bill& b) const {
            return amount > b.amount;
        }

        void display() const {
            cout << "Items: " << items << ", Total: Rs. " << amount;
        }
};

int main() {
    Bill b1(3, 450.0), b2(5, 700.0);

    cout << "b1 = "; 
    b1.display(); 
    cout << endl;
    cout << "b2 = "; 
    b2.display(); 
    cout << endl;

    Bill b3 = b1 + b2;
    cout << "b1 + b2 = "; 
    b3.display(); 
    cout << endl;

    cout << "b1 > b2 ? " << (b1 > b2 ? "true" : "false") << endl;
    cout << "b2 > b1 ? " << (b2 > b1 ? "true" : "false") << endl;
    return 0;
}
