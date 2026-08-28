#include <iostream>

using namespace std;

void inspect(int var);
void inspect(int* ptr);
void inspect(int* ptr, int size);

int main()
{
    int val = 42;
    cout << "--- Demonstrating inspect() with an integer variable ---" << endl;
    inspect(val);
    
    int* p = &val;
    cout << "\n--- Demonstrating inspect() with an integer pointer ---" << endl;
    inspect(p);
    
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "\n--- Demonstrating inspect() with an integer array ---" << endl;
    inspect(arr, size);
    
    return 0;
}

// Display the value of an integer variable.
void inspect(int var)
{
    cout << "Value of integer variable: " << var << endl;
}

// Display the value stored at an integer pointer.
void inspect(int* ptr)
{
    if (ptr != nullptr) {
        cout << "Value stored at integer pointer: " << *ptr << endl;
    } else {
        cout << "Pointer is null." << endl;
    }
}

// Display all elements of an integer array using a pointer and its size.
void inspect(int* ptr, int size)
{
    if (ptr == nullptr) return;
    cout << "Elements of the integer array: ";
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i);
        if (i < size - 1)
            cout << ", ";
    }
    cout << "}";
    cout << endl;
}
