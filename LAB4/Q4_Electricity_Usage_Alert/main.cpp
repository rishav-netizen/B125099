#include <iostream>
#include <string>

using namespace std;

class ElectricMeter {
    private:
        int meterNumber;
        string consumerName;
        int unitsConsumed;

    public:
        ElectricMeter()
        {

        }

        ElectricMeter(int number, string name, int units) {
            meterNumber = number;
            consumerName = name;
            unitsConsumed = units;
        }

        void Input() {
            cout << "Enter meter number: ";
            cin >> meterNumber;

            cout << "Enter consumer name: ";
            cin.ignore();
            getline(cin, consumerName);

            cout << "Enter units consumed: ";
            cin >> unitsConsumed;
        }

        friend void checkUsage(ElectricMeter e);
};

void checkUsage(ElectricMeter e) {
    cout <<  "\nCustomer Details are as follows: \n";
    cout << "Meter Number: " << e.meterNumber << endl;
    cout << "Consumer Name: " << e.consumerName << endl;
    cout << "Units Consumed: " << e.unitsConsumed << endl;

    if (e.unitsConsumed < 100)
        cout << "Usage: Low Usage" << endl;
    else if (e.unitsConsumed <= 300)
        cout << "Usage: Moderate Usage" << endl;
    else
        cout << "Usage: High Usage" << endl;
}

int main() {
    ElectricMeter e;

    e.Input();
    checkUsage(e);

    return 0;
}