#include <iostream>

using namespace std;

void convert(int km);
void convert(long m);
void convert(double km);

int main() {
    int km;
    cout << "Enter distance kilometers: ";
    cin >> km;
    
    long m;
    cout << "Enter distance in meters: ";
    cin >> m;
    
    double d_km = 4.5;
    cout << "Enter floating point distance in kilometers: ";
    cin >> d_km;
    
    cout << "\n--- Distance Converter ---" << endl;
    convert(km);
    convert(m);
    convert(d_km);
    return 0;
}

// Convert a distance given in kilometers into meters.
void convert(int km) 
{
    cout << km << " km = " << (km * 1000) << " meters" << endl;
}

// Convert a distance given in kilometers into meters.
//? using long to differentiate from int (kilometers)
void convert(long m) 
{
    cout << m << " meters = " << (m * 100) << " centimeters" << endl;
}

// Convert a floating-point distance given in kilometers into meters.
void convert(double km) 
{
    cout << km << " km = " << (km * 1000.0) << " meters" << endl;
}