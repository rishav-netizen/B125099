#include <iostream>
#include <string>
using namespace std;

class WaterBill
{
private:
    int consumerNumber;
    string consumerName;
    float waterConsumption;
    float billAmount;

public:
    void acceptDetails()
    {
        cout << "Enter Consumer Number: ";
        cin >> consumerNumber;
        cin.ignore();

        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);

        cout << "Enter Water Consumption (in litres): ";
        cin >> waterConsumption;
    }

    void calculateBill()
    {
        if (waterConsumption <= 500)
        {
            billAmount = waterConsumption * 2;
        }
        else if (waterConsumption <= 1000)
        {
            billAmount = (500 * 2) + ((waterConsumption - 500) * 3);
        }
        else
        {
            billAmount = (500 * 2) + (500 * 3) + ((waterConsumption - 1000) * 5);
        }
    }

    void displayBill()
    {
        cout << "\nWater Bill Details are as follows: \n";
        cout << "Consumer Number: " << consumerNumber << endl;
        cout << "Consumer Name: " << consumerName << endl;
        cout << "Water Consumption: " << waterConsumption << " litres" << endl;
        cout << "Total Bill: ₹. " << billAmount << endl;
    }
};

int main()
{
    WaterBill consumer;

    consumer.acceptDetails();
    consumer.calculateBill();
    consumer.displayBill();

    return 0;
}