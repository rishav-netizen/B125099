#include <iostream>
#include <string>

using namespace std;

class MobileRecharge
{
private:
    string mobileNumber;
    string customerName;
    float balance;

public:
    void acceptDetails()
    {
        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Mobile Number: ";
        cin >> mobileNumber;

        cout << "Enter Current Balance: ";
        cin >> balance;
    }

    void rechargeBalance()
    {
        float amount;

        cout << "\nEnter amount to add to balance: ";
        cin >> amount;

        balance += amount;

        cout << "Balance recharged successfully!\n";
    }

    void deductBalance()
    {
        float planAmount;

        cout << "\nEnter recharge plan amount: ";
        cin >> planAmount;

        if (planAmount <= balance)
        {
            balance -= planAmount;
            cout << "Recharge successful!\n";
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    void displayBalance()
    {
        cout << "\n----- Customer Details -----\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Mobile Number : " << mobileNumber << endl;
        cout << "Current Balance : Rs. " << balance << endl;
    }
};

int main()
{
    MobileRecharge user;

    user.acceptDetails();
    user.rechargeBalance();
    user.deductBalance();
    user.displayBalance();

    return 0;
}