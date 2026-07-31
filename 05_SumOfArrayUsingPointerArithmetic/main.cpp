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
int ArrSum(Array arr);

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
    cout << "The sum of all the elements is: " << ArrSum(arr) << endl;
    
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


int ArrSum(Array arr)
{
    int total = 0;
    int l = arr.length;
    for (int i = 0; i < l; i++)
    {
        int current = *(arr.A + i); 
        // since arr.A is the base address, we add i to it and dereference it
        total += current;
    }
    return total;
}
