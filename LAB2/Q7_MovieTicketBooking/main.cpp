#include <iostream>
#include <string>

using namespace std;

class MovieTicket
{
private:
    string movieName;
    float ticketPrice;
    int numberOfTickets;
    float totalCost;

public:
    void acceptDetails()
    {
        cout << "Enter Movie Name: ";
        getline(cin, movieName);

        cout << "Enter Ticket Price: ";
        cin >> ticketPrice;

        cout << "Enter Number of Tickets: ";
        cin >> numberOfTickets;
    }

    void calculateCost()
    {
        totalCost = ticketPrice * numberOfTickets;
    }

    void displaySummary()
    {
        cout << "\n----- Booking Summary -----\n";
        cout << "Movie Name: " << movieName << endl;
        cout << "Ticket Price: Rs. " << ticketPrice << endl;
        cout << "Number of Tickets: " << numberOfTickets << endl;
        cout << "Total Cost: Rs. " << totalCost << endl;
    }
};

int main()
{
    MovieTicket ticket;

    ticket.acceptDetails();
    ticket.calculateCost();
    ticket.displaySummary();

    return 0;
}