#include <iostream>
using namespace std;

void Reverse(int *arr, int length);
void Swap(int *a, int *b);
void Display(int *arr, int length);

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate an array of n integers
    int* arr = new int[n]();

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Entered array: ";
    Display(arr, n);
    Reverse(arr, n);
    cout << "After reversing: ";
    Display(arr, n);

    // Properly deallocate the dynamically allocated memory
    delete[] arr;
    arr = nullptr;
    return 0;
}

void Reverse(int *arr, int length)
{
    for (int i = 0; i < length/2; i++)
    {
        Swap(&arr[i], &arr[length-i-1]);
    }
}

void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
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