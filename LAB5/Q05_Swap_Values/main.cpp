#include <iostream>

using namespace std;

void swapData(int &a, int &b);
void swapData(float &a, float &b);
void swapData(int *a, int *b);

int main()
{
    int a, b;
    cout << "Enter two integers to swap (using references): ";
    cin >> a >> b;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapData(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    float x, y;
    cout << "\nEnter two floating-point numbers to swap (using references): ";
    cin >> x >> y;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapData(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    int p, q;
    cout << "\nEnter two integers to swap (using pointers): ";
    cin >> p >> q;
    cout << "Before swap: p = " << p << ", q = " << q << endl;
    swapData(&p, &q); // Passes the addresses
    cout << "After swap: p = " << p << ", q = " << q << endl;

    return 0;
}

// Swap two integer values using references.
void swapData(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Swap two floating-point values using references.
void swapData(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

// Swap two integer values using pointers.
void swapData(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
