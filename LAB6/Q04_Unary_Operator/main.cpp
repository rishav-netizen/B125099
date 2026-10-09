#include <iostream>
using namespace std;

class AccountBalance {
private:
    double balance;

public:
    AccountBalance(double b = 0) : balance(b) {}

    AccountBalance operator-() const {
        return AccountBalance(-balance);
    }

    void display() const {
        cout << "Balance: Rs. " << balance;
    }
};

int main() {
    AccountBalance a1(5000);
    AccountBalance a2 = -a1;

    cout << "Original:      "; a1.display(); cout << endl;
    cout << "After unary -: "; a2.display(); cout << endl;
    cout << "Original still: "; a1.display(); cout << " (unchanged)" << endl;
    return 0;
}
