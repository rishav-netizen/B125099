#include <iostream>
using namespace std;

// Pass the dynamically allocated array using a pointer
void acceptElements(int* arr, int n) {
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int calculateSum(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int findSmallest(int* arr, int n) {
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) smallest = arr[i];
    }
    return smallest;
}

int findLargest(int* arr, int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
    }
    return largest;
}

void displayResults(int sum, int smallest, int largest) {
    cout << "\n--- Results ---\n";
    cout << "Sum: " << sum << endl;
    cout << "Smallest element: " << smallest << endl;
    cout << "Largest element: " << largest << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate an array
    int* arr = new int[n];

    acceptElements(arr, n);
    
    int sum = calculateSum(arr, n);
    int smallest = findSmallest(arr, n);
    int largest = findLargest(arr, n);
    
    displayResults(sum, smallest, largest);

    // Release memory
    delete[] arr;
    arr = nullptr;
    
    return 0;
}
