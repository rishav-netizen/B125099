#include <iostream>
#include <string>

using namespace std;

// Class definition for hostel fees
class HostelFee
{
private:
    string student_name;
    int hostel_ID;
    float monthly_fee;
    int number_of_months;
    float total_fee;
    char delayed;

public:
    void acceptDetails()
    {
        cout << "Enter Student Name: ";
        getline(cin, student_name);

        cout << "Enter Hostel ID: ";
        cin >> hostel_ID;

        cout << "Enter Monthly Fee: ";
        cin >> monthly_fee;

        cout << "Enter Number of Months: ";
        cin >> number_of_months;

        cout << "Is payment delayed? (Y/N): ";
        cin >> delayed;
    }

    void calculateFee()
    {
        total_fee = monthly_fee * number_of_months;
    }

    void applyFine()
    {
        if (delayed == 'Y' || delayed == 'y')
        {
            total_fee += 500;
        }
    }

    void displayDetails()
    {
        cout << "\nHostel Fee Details are as follows: \n";
        cout << "Student Name: " << student_name << endl;
        cout << "Hostel ID: " << hostel_ID << endl;
        cout << "Monthly Fee: Rs. " << monthly_fee << endl;
        cout << "Number of Months: " << number_of_months << endl;

        if (delayed == 'Y' || delayed == 'y')
            cout << "Late Fine: Rs. 500" << endl;
        else
            cout << "Late Fine: Rs. 0" << endl;

        cout << "Final Amount Payable: Rs. " << total_fee << endl;
    }
};

int main()
{
    HostelFee student;

    student.acceptDetails();
    student.calculateFee();
    student.applyFine();
    student.displayDetails();

    return 0;
}