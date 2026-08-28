#include <iostream>

using namespace std;

void evaluate(int a, int b);
void evaluate(int a, int b, int c);
void evaluate(float a, float b);
void evaluate(int arr[], int size);
void evaluate(int* a, int* b);

int main()
{
    int a, b, c;
    cout << "Enter two integers: ";
    cin >> a >> b;
    evaluate(a, b);
    
    cout << "\nEnter a third integer: ";
    cin >> c;
    evaluate(a, b, c);
    
    float x, y;
    cout << "\nEnter two floating-point values: ";
    cin >> x >> y;
    evaluate(x, y);
    
    int n;
    cout << "\nEnter the size of the integer array: ";
    cin >> n;
    int arr[100];
    if (n > 0) {
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];
        evaluate(arr, n);
    }
    
    int p, q;
    cout << "\nEnter two integers to evaluate through pointers: ";
    cin >> p >> q;
    evaluate(&p, &q);
    
    return 0;
}

// Calculate the average of two integers.
void evaluate(int a, int b)
{
    cout << "Average of two integers (" << a << ", " << b << "): " << (a + b) / 2.0 << endl;
}

// Calculate the average of three integers.
void evaluate(int a, int b, int c)
{
    cout << "Average of three integers (" << a << ", " << b << ", " << c << "): " << (a + b + c) / 3.0 << endl;
}

// Calculate the average of two floating-point values.
void evaluate(float a, float b)
{
    cout << "Average of two floating-point values (" << a << ", " << b << "): " << (a + b) / 2.0 << endl;
}

// Calculate the average of all elements of an integer array.
void evaluate(int arr[], int size)
{
    if (size <= 0) return;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Average of array elements: " << (double)sum / size << endl;
}

// Calculate the average of two integer values accessed through pointers.
void evaluate(int* a, int* b)
{
    if (a != nullptr && b != nullptr) {
        cout << "Average of two integers from pointers (" << *a << ", " << *b << "): " << (*a + *b) / 2.0 << endl;
    }
}
