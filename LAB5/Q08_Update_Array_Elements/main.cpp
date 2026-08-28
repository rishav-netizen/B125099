#include <iostream>

using namespace std;

void update(int &var, int amount);
void update(float &var, float amount);
void update(int arr[], int size, int amount);

int main()
{
    int int_val, int_inc;
    cout << "Enter an integer and the amount to increase: ";
    cin >> int_val >> int_inc;
    cout << "Before update: " << int_val << endl;
    update(int_val, int_inc);
    cout << "After update: " << int_val << endl;

    float float_val, float_inc;
    cout << "\nEnter a floating-point value and the amount to increase: ";
    cin >> float_val >> float_inc;
    cout << "Before update: " << float_val << endl;
    update(float_val, float_inc);
    cout << "After update: " << float_val << endl;

    int n;
    cout << "\nEnter size of integer array: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int arr_inc;
    cout << "Enter the amount to increase every element by: ";
    cin >> arr_inc;
    
    cout << "Before update: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    update(arr, n, arr_inc);
    
    cout << "After update: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// Increase an integer variable by a specified amount.
void update(int &var, int amount)
{
    var += amount;
}

// Increase a floating-point variable by a specified amount.
void update(float &var, float amount)
{
    var += amount;
}

// Increase every element of an integer array by a specified amount.
void update(int arr[], int size, int amount)
{
    for (int i = 0; i < size; i++) {
        arr[i] += amount;
    }
}
