#include <iostream>

using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    // Allocate memory for the row pointers first
    int** mat1 = new int*[m];
    int** mat2 = new int*[m];
    int** result = new int*[m];

    // Allocate memory for each row separately
    for (int i = 0; i < m; i++) {
        mat1[i] = new int[n]();
        mat2[i] = new int[n]();
        result[i] = new int[n]();
    }

    cout << "\nEnter elements of Matrix 1 (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "\nEnter elements of Matrix 2 (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat2[i][j];
        }
    }

    // Perform matrix addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    cout << "\n--- Resulting Matrix (Addition) ---\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    // Deallocate dynamically allocated memory
    for (int i = 0; i < m; i++) {
        // Use delete[] for every allocated row
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] result[i];
    }

    // Use delete[] and equate to nullptr for the array of row pointers
    delete[] mat1;
    delete[] mat2;
    delete[] result;
    mat1 = nullptr;
    mat2 = nullptr;
    result = nullptr;

    return 0;
}
