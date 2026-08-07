#include <iostream>
using namespace std;

// Class to store temperature and perform conversion
class Temperature
{
private:
    float celsius, fahrenheit;

public:
    // Takes temperature in Celsius from the user
    void inputTemperature()
    {
        cout << "Enter temperature in Celsius: ";
        cin >> celsius;
    }

    // Converts Celsius to Fahrenheit
    void convertToFahrenheit()
    {
        fahrenheit = (9.0 / 5.0) * celsius + 32;
    }

    // Displays both temperatures
    void displayTemperature()
    {
        cout << "\nTemperature Details\n";
        cout << "-------------------\n";
        cout << "Celsius    : " << celsius << " °C" << endl;
        cout << "Fahrenheit : " << fahrenheit << " °F" << endl;
    }
};

// main function
int main()
{
    // Create an object of the Temperature class
    Temperature t;

    t.inputTemperature();
    t.convertToFahrenheit();
    t.displayTemperature();

    return 0;
}