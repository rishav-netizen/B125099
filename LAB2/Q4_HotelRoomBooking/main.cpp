#include <iostream>

using namespace std;

// Hotel Room class to manage customer details
class HotelRoom
{
    private:
        int room_number, days_stayed;
        string name;
        int cost_per_day, total_rent;

    public:
        HotelRoom(int cost)
        {
            cost_per_day = cost;
        }
        void acceptDetails();
        void totalRent();
        void displayDetails();
};

// Function to accept customer details
void HotelRoom::acceptDetails()
{
    cout << "Enter your hotel stay details:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Room Number: ";
    cin >> room_number;
    cout << "Number of days stayed: ";
    cin >> days_stayed;
}

// Function to calculate the total rent for the person
void HotelRoom::totalRent()
{
    int total_rent = days_stayed * cost_per_day;
    cout << "Total rent: " << total_rent << endl;
}

void HotelRoom::displayDetails()
{
    cout << "\nYour details are as follows:\n";
    cout << "Name: " << name << endl;
    cout << "Room Number: " << room_number << endl;
    cout << "Days stayed: " << days_stayed << endl;
    // cout << "The total rent would be: " << total_rent << endl;
}

int main(){
    HotelRoom r(100);
    r.acceptDetails();

    r.displayDetails();
    r.totalRent();
    return 0;
}