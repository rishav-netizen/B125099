#include <iostream>
using namespace std;

void Display(int *arr, int length);

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate an integer array
    int* arr = new int[n];
    int evenCount = 0, oddCount = 0;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        // Count even and odd using modulus operator
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << "\n--- Results ---\n";
    cout << "Array: ";
    Display(arr, n);
    cout << "Even numbers count: " << evenCount << endl;
    cout << "Odd numbers count: " << oddCount << endl;

    // Release allocated memory
    delete[] arr;
    arr = nullptr;

    return 0;
}

void Display(int arr[], int length)
{
    cout << "{";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i];
        if (i < length - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}
