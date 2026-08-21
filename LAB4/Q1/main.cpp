#include <iostream>
#include <string>
using namespace std;

class Weather {
    private:
        string cityName;
        float temperature;
        string weatherCondition;

    public:
        Weather(string city, float temp, string condition) {
            cityName = city;
            temperature = temp;
            weatherCondition = condition;
        }

        friend void generateReport(Weather);
};

// global friend function to access private class functions
void generateReport(Weather current) {
    cout << "City: " << current.cityName << endl;
    cout << "Temperature: " << current.temperature << " °C" << endl;
    cout << "Condition: " << current.weatherCondition << endl;
    cout << "Classification: ";
    if (current.temperature > 35)
        cout << "Very Hot" << endl;
    else if (current.temperature >= 20)
        cout << "Pleasant" << endl;
    else
        cout << "Cool" << endl;
}

int main() {
    Weather w("Bhubaneswar", 32, "Sunny");
    generateReport(w);

    return 0;
}