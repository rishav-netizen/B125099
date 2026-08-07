#include <iostream>

using namespace std;

class Car
{
    private:
        int model;
        string brand, number;
    public:
        void DisplayDetails();
        void InputDetails();
};

void Car::InputDetails()
{
    cout << "Enter the car's details:\nCar Number: ";
    cin >> number;
    cout << "Model Year: ";
    cin >> model;
    cout << "Brand Name: ";
    cin.ignore();
    getline(cin, brand);
}

void Car::DisplayDetails()
{
    cout << "\nThe car details are as follows: " << endl;
    cout << "Brand Name: " << brand << "\nModel: " << model << "\nCar Number: " << number << endl;
}


int main(){
    Car c1;
    c1.InputDetails();
    c1.DisplayDetails();
    return 0;
}