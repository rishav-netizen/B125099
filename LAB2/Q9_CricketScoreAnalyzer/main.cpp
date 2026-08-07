#include <iostream>
#include <string>
using namespace std;

class CricketPlayer
{
private:
    string playerName;
    int matchesPlayed;
    int totalRuns;
    float battingAverage;
    string performance;

public:
    void acceptDetails()
    {
        cout << "Enter Player Name: ";
        getline(cin, playerName);

        cout << "Enter Matches Played: ";
        cin >> matchesPlayed;

        cout << "Enter Total Runs Scored: ";
        cin >> totalRuns;
    }

    void calculateAverage()
    {
        battingAverage = (float)totalRuns / matchesPlayed;
    }

    void classifyPerformance()
    {
        if (battingAverage >= 50)
            performance = "Excellent";
        else if (battingAverage >= 35)
            performance = "Good";
        else if (battingAverage >= 20)
            performance = "Average";
        else
            performance = "Poor";
    }

    void displayReport()
    {
        cout << "\n----- Player Report -----\n";
        cout << "Player Name: " << playerName << endl;
        cout << "Matches Played: " << matchesPlayed << endl;
        cout << "Total Runs Scored: " << totalRuns << endl;
        cout << "Batting Average: " << battingAverage << endl;
        cout << "Performance: " << performance << endl;
    }
};

int main()
{
    CricketPlayer player;

    player.acceptDetails();
    player.calculateAverage();
    player.classifyPerformance();
    player.displayReport();

    return 0;
}