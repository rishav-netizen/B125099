#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate memory for two integers
    int* num1 = new int;
    int* num2 = new int;

    cout << "Enter first number: ";
    cin >> *num1;
    cout << "Enter second number: ";
    cin >> *num2;

    cout << "\n--- Results ---\n";
    cout << "Sum: " << (*num1 + *num2) << endl;
    cout << "Difference: " << (*num1 - *num2) << endl;
    cout << "Product: " << (*num1 * *num2) << endl;
    
    if (*num2 != 0) {
        cout << "Quotient: " << (float)(*num1) / (*num2) << endl;
    } else { // if num2 is zero
        cout << "Quotient: Division by zero error!" << endl;
    }

    // Release dynamically allocated memory
    delete num1;
    delete num2;
    num1 = nullptr;
    num2 = nullptr;

    return 0;
}



