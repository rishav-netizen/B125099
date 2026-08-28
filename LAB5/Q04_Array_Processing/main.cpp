#include <iostream>

using namespace std;

void process(int arr[], int size);
void process(float arr[], int size);
void process(int arr[], int size, int k);

int main()
{
    int n;
    cout << "Enter size of integer array: ";
    cin >> n;
    int int_arr[100];
    cout << "Enter " << n << " integer elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> int_arr[i];  
    } 
    
    int m;
    cout << "\nEnter size of floating-point array: ";
    cin >> m;
    float float_arr[100];
    cout << "Enter " << m << " floating-point elements: ";
    for (int i = 0; i < m; i++)
    {
        cin >> float_arr[i];
    }
    
    int k;
    cout << "\nEnter value of k for integer array sum: ";
    cin >> k;
    
    cout << "\nResults:" << endl;
    process(int_arr, n);
    process(float_arr, m);
    process(int_arr, n, k);
    
    return 0;
}

// Calculate the sum of all elements of an integer array.
void process(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Sum of integer array elements: " << sum << endl;
}

// Calculate the sum of all elements of a floating-point array.
void process(float arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Sum of floating-point array elements: " << sum << endl;
}

// Calculate the sum of only the first k elements of an integer array.
void process(int arr[], int size, int k)
{
    int sum = 0;
    int limit = (k < size) ? k : size;
    for (int i = 0; i < limit; i++) {
        sum += arr[i];
    }
    cout << "Sum of first " << limit << " elements of integer array: " << sum << endl;
}
