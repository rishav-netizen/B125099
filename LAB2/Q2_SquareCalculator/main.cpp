#include <iostream>
using namespace std;

// Class to store the side of a square and perform calculations
class Square
{
private:
    float side;
    float area;
    float perimeter;

public:
    // Takes the side length from the user
    void inputSide()
    {
        cout << "Enter the side of the square: ";
        cin >> side;
    }

    // Calculates the area of the square
    void calculateArea()
    {
        area = side * side;
    }

    // Calculates the perimeter of the square
    void calculatePerimeter()
    {
        perimeter = 4 * side;
    }

    // Displays the side, area and perimeter
    void displayResults()
    {
        cout << "\nSquare Details\n";
        cout << "--------------\n";
        cout << "Side      : " << side << endl;
        cout << "Area      : " << area << endl;
        cout << "Perimeter : " << perimeter << endl;
    }
};

int main()
{
    Square s; // Create an object of the Square class

    s.inputSide();
    s.calculateArea();
    s.calculatePerimeter();
    s.displayResults();

    return 0;
}