#include <iostream>
#include <string>
using namespace std;

class ElectricMeter {
private:
    int meterNumber;
    string consumerName;
    int unitsConsumed;

public:
    ElectricMeter(int number, string name, int units) {
        meterNumber = number;
        consumerName = name;
        unitsConsumed = units;
    }

    friend void checkUsage(ElectricMeter e);
};

void checkUsage(ElectricMeter e) {
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
    ElectricMeter e(101, "Rishav", 250);
    checkUsage(e);

    return 0;
}