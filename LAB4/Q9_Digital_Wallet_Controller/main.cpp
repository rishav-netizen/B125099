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

    friend class WalletManager;
};

class WalletManager {
public:
    void displayDetails(DigitalWallet &w) {
        cout << "User: " << w.userName << endl;
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
    DigitalWallet wallet("Rishav", 1000, true);
    WalletManager manager;

    manager.displayDetails(wallet);

    manager.addMoney(wallet, 500);
    manager.deductMoney(wallet, 300);

    cout << "\nAfter Transactions:\n";
    manager.displayDetails(wallet);

    manager.disableWallet(wallet);
    manager.displayStatus(wallet);

    return 0;
}