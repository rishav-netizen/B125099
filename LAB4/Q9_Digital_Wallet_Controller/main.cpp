#include <iostream>
#include <string>

using namespace std;

class WalletManager;

class DigitalWallet {
    private:
        string userName;
        double walletBalance;
        bool walletStatus;

    public:
        DigitalWallet(string name, double balance, bool status) {
            userName = name;
            walletBalance = balance;
            walletStatus = status;
        }

        void Input() {
            cout << "Enter user name: ";
            getline(cin, userName);

            cout << "Enter wallet balance: ";
            cin >> walletBalance;

            cout << "Enter wallet status (1 for Active, 0 for Disabled): ";
            cin >> walletStatus;
        }

        friend class WalletManager;
};

class WalletManager {
    public:
        void displayDetails(DigitalWallet &w) {
            cout << "\n\n--USER DETAILS--\nUser: " << w.userName << endl;
            cout << "Balance: Rs. " << w.walletBalance << endl;
            cout << "Status: " << (w.walletStatus ? "Active" : "Disabled")
                 << endl;
        }

        void addMoney(DigitalWallet &w, double amount) {
            if (w.walletStatus)
                w.walletBalance += amount;
        }

        void deductMoney(DigitalWallet &w, double amount) {
            if (w.walletStatus && amount <= w.walletBalance)
                w.walletBalance -= amount;
            else
                cout << "Insufficient balance or wallet disabled." << endl;
        }

        void disableWallet(DigitalWallet &w) {
            w.walletStatus = false;
        }

        void displayStatus(DigitalWallet &w) {
            cout << "Wallet Status: "
                 << (w.walletStatus ? "Active" : "Disabled") << endl;
        }
};

int main() {
    DigitalWallet wallet("", 0, false);
    WalletManager manager;

    wallet.Input();

    manager.displayDetails(wallet);

    int added, deducted;
    cout << "Enter amount to add: ";
    cin >> added;
    cout << "Enter amount to use: ";
    cin >> deducted;
    manager.addMoney(wallet, added);
    manager.deductMoney(wallet, deducted);

    cout << "\nAfter Transactions:\n";
    manager.displayDetails(wallet);

    manager.disableWallet(wallet);
    manager.displayStatus(wallet);

    return 0;
}