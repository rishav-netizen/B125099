#include <iostream>
#include <cctype>

using namespace std;

class Wallet
{
    private:
        int walletID;
        double balance;
        double *transactions;
        int count;

    public:
        Wallet(int id, double b) 
        {
            walletID = id;
            balance = b;
            count = 0;
            transactions = new double[100];
        }

        Wallet()
        {
            walletID = 0;
            balance = 0;
            count = 0;
            transactions = new double[100];
        }

        void input() 
        {
            cout << "Enter Wallet ID: ";
            cin >> walletID;

            cout << "Enter initial balance: ";
            cin >> balance;
            while (balance <= 0)
            {
                cout << "Balance cant be negative try again: ";
                cin >> balance;
            }
        }

        // Sign determines deposit/withdrawal
        void transaction(double amount) 
        {
            balance += amount;
            transactions[count++] = amount;
        }

        // d = deposit, w = withdrawal
        void transaction(double amount, char type) 
        {
            type = tolower(type);
            if (type == 'd')
            {
                balance += amount;
                transactions[count++] = amount;
            }
            else if (type == 'w')
            {
                balance -= amount;
                transactions[count++] = -amount;
            }
        }

        void display() 
        {
            cout << "\tWallet ID: " << walletID << "\n\tBalance: " << balance << endl;
        }

        friend void compareWallet(const Wallet& w1, const Wallet& w2);

        ~Wallet() 
        {
            delete[] transactions;
            transactions = nullptr;
        }
};

void compareWallet(const Wallet& w1, const Wallet& w2) 
{
    if (w1.balance > w2.balance)
    {
        cout << "Wallet " << w1.walletID << " has larger balance.\n";
    }
    else if (w2.balance > w1.balance)
    {
        cout << "Wallet " << w2.walletID << " has larger balance.\n";
    }
    else
    {
        cout << "Both wallets have equal balance.\n";
    }
}

int main() 
{
    Wallet *w1 = new Wallet;
    Wallet *w2 = new Wallet;

    cout << "Enter details for Wallet 1:\n";
    w1->input();

    cout << "\nEnter details for Wallet 2:\n";
    w2->input();

    double amount;
    char type;

    cout << "\nWallet 1 Transaction\n";
    cout << "Enter transaction amount (+ for deposit, - for withdrawal): ";
    cin >> amount;
    w1->transaction(amount);

    cout << "\nWallet 2 Transaction\n";
    cout << "Enter transaction type (D for deposit, W for withdrawal): ";
    cin >> type;
    type = tolower(type); 
    while (type != 'd' && type != 'w')
    {
        cout << "Invalid input, try again: ";
        cin >> type;
        type = tolower(type); 
    }
    cout << "Enter amount: ";
    cin >> amount;
    w2->transaction(amount, type);

    cout << "\nWallet Details:\n";
    cout << '\n';
    w1->display();
    cout << '\n';
    w2->display();
    cout << '\n';

    compareWallet(*w1, *w2);

    delete w1;
    w1 = nullptr;
    delete w2;
    w2 = nullptr;
    
    return 0;
}