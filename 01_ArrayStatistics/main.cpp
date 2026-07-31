#include <iostream>
#include <limits.h>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(Array arr);
void Input(Array *arr);
int ArrMax(Array arr);
int ArrMin(Array arr);
float ArrAvg(Array arr);

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
    cout << "The maximum element is: " << ArrMax(arr) << endl;
    cout << "The minimum element is: " << ArrMin(arr) << endl;
    cout << "The average of all the elements is: " << ArrAvg(arr) << endl;
    
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

int ArrMax(Array arr)
{
    int maximum = INT_MIN;
    for (int i = 0, l = arr.length; i < l; i++)
    {
        int current = arr.A[i];
        maximum = (current >= maximum) ? current : maximum;
    }
    return maximum;
}

int ArrMin(Array arr)
{
    int minimum = INT_MAX;
    for (int i = 0, l = arr.length; i < l; i++)
    {
        int current = arr.A[i];
        minimum = (current <= minimum) ? current : minimum;
    }
    return minimum;
}

float ArrAvg(Array arr)
{
    int total = 0;
    int l = arr.length;
    for (int i = 0; i < l; i++)
    {
        int current = arr.A[i];
        total += current;
    }
    return (float)total/l;
}
