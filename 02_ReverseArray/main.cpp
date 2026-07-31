#include <iostream>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(Array arr);
void Input(Array *arr);
void Reverse(Array *arr);
void Swap(int *a, int *b);

int main(){
    Array arr;
    cout << "Enter array size: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    int length;
    cout << "Enter the number of integers: ";
    cin >> length;
    while (length < 0 || length > arr.size)
    {
        cout << "Invalid input! Length must be smaller than size!" << endl;
        cout << "Try again: ";
        cin >> length;
    }
    arr.length = length;

    Input(&arr);
    Display(arr);
    Reverse(&arr);
    cout << "After reversing, ";
    Display(arr);
    
    return 0;
}

void Display(Array arr)
{

    cout << "Elements of the array are: {";
    for (int i = 0; i < arr.length; i++)
    {   
        cout << arr.A[i];
        if (i < arr.length - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}

void Input(Array *arr)
{
    for (int i = 0, l = arr -> length; i < l; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr -> A[i];
    }

}

void Reverse(Array *arr)
{
    for (int i = 0, l = arr -> length; i < l/2; i++)
    {
        Swap(&arr->A[i], &arr->A[l-i-1]);
    }
}

void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}