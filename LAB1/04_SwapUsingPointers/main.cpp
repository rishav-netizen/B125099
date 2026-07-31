#include <iostream>

using namespace std;

void Swap(int *a, int *b);

int main(){
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    Swap(&a, &b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    return 0;
}

void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}