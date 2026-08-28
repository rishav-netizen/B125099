#include <iostream>

using namespace std;

int abs_val(int n);
float abs_val(float n);
void nearValue(int a, int b);
void nearValue(float a, float b);
void nearValue(int arr[], int size);

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    nearValue(a, b);
    
    float x, y;
    cout << "\nEnter two floating-point values: ";
    cin >> x >> y;
    nearValue(x, y);
    
    int n;
    cout << "\nEnter the size of the integer array: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    nearValue(arr, n);
    
    return 0;
}

// Helper function to calculate absolute value for int
int abs_val(int n)
{
    return (n < 0) ? -n : n;
}

// Helper function to calculate absolute value for float
float abs_val(float n)
{
    return (n < 0) ? -n : n;
}

// Which of two integers is closer to zero.
void nearValue(int a, int b)
{
    if (abs_val(a) < abs_val(b)) cout << a << " is closer to zero than " << b << endl;
    else if (abs_val(b) < abs_val(a)) cout << b << " is closer to zero than " << a << endl;
    else cout << a << " and " << b << " are at the same distance from zero." << endl;
}

// Which of two floating-point values is closer to zero.
void nearValue(float a, float b)
{
    if (abs_val(a) < abs_val(b)) cout << a << " is closer to zero than " << b << endl;
    else if (abs_val(b) < abs_val(a)) cout << b << " is closer to zero than " << a << endl;
    else cout << a << " and " << b << " are at the same distance from zero." << endl;
}

// Which element of an integer array is closest to zero.
void nearValue(int arr[], int size)
{
    if (size <= 0) return;
    int closest = arr[0];
    for (int i = 1; i < size; i++) {
        if (abs_val(arr[i]) < abs_val(closest)) {
            closest = arr[i];
        }
    }
    cout << closest << " is the element closest to zero in the array." << endl;
}
