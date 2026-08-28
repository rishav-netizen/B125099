#include <iostream>
#define PI 3.141592f

using namespace std;

void area(double side);
void area(double length, double breadth);
void area(float radius);

int main() 
{
    double side, length, breadth;
    float radius;
    
    cout << "Enter the side of the square: ";
    cin >> side;
    area(side);
    
    cout << "\nEnter the length and breadth of the rectangle: ";
    cin >> length >> breadth;
    area(length, breadth);
    
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    area(radius);
    
    return 0;
}

// Area of a square
void area(double side)
{
    cout << "Area of the square: " << side * side << " sq. units" << endl;
}

// Area of a rectangle
void area(double length, double breadth)
{
    cout << "Area of the rectangle: " << length * breadth << " sq. units" << endl;
}

// Area of a circle
// Using float to differentiate from the single double parameter for square
void area(float radius)
{
    cout << "Area of the circle: " << PI * radius * radius << " sq. units" << endl;
}