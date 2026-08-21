#include <iostream>

using namespace std;

class UserAccount {
    private:
        string username;
        int loginAttempts;
        string accountStatus;

    public:
        UserAccount(string user, int attempts, string status) {
            username = user;
            loginAttempts = attempts;
            accountStatus = status;
        }

        friend void checkAccount(UserAccount);
};

void checkAccount(UserAccount u) {
    cout << "Username: " << u.username << endl;
    cout << "Login Attempts: " << u.loginAttempts << endl;
    cout << "Account Status: ";

    if (u.loginAttempts >= 3)
    {
        cout << "Locked\n";
    }
    else
    {
        cout << "Active\n";
    }
}

int main() {
    UserAccount u("Ramesh Pandey", 2, "Active");
    checkAccount(u);

    return 0;
}