#include <iostream>

using namespace std;

void information(const char arr[]);
void information(const char arr[], char target);
void information(const char arr[], char target, int k);

int main()
{
    int max_len;
    cout << "Enter the maximum string length you want to allocate: ";
    cin >> max_len;

    // Dynamically allocate memory for the character array
    char* str = new char[max_len + 1];

    cout << "Enter a string (character array without spaces): ";
    cin >> str;
    
    char ch;
    cout << "Enter a character to search for: ";
    cin >> ch;
    
    int k;
    cout << "Enter the number of positions (k) to examine: ";
    cin >> k;
    
    cout << "\n--- Results ---" << endl;
    information(str);
    information(str, ch);
    information(str, ch, k);
    
    // Free the dynamically allocated memory
    delete[] str;
    
    return 0;
}

// Find the length of a character array.
void information(const char arr[])
{
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    cout << "Length of the character array: " << len << endl;
}

// Count the occurrence of a specified character in a character array.
void information(const char arr[], char target)
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == target) count++;
    }
    cout << "Occurrence of '" << target << "' in the string: " << count << endl;
}

// Count the occurrence of a specified character within the first k positions.
void information(const char arr[], char target, int k)
{
    int count = 0;
    for (int i = 0; i < k && arr[i] != '\0'; i++) {
        if (arr[i] == target) count++;
    }
    cout << "Occurrence of '" << target << "' within the first " << k << " positions: " << count << endl;
}
