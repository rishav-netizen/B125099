#include <iostream>
using namespace std;

int LinearSearch(int *arr, int length, int key);

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
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;
    int index = LinearSearch(arr, n, key);

    if (index == -1)
    {
        cout << "Element not found!\n";
    }
    else 
    {
        cout << "Element found at index: " << index << endl;
    }

    // Release allocated memory
    delete[] arr;
    arr = nullptr;

    return 0;
}

int LinearSearch(int *arr, int length, int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
    
}