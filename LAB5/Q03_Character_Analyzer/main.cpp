#include <iostream>
#include <cctype>

void check(int n);
void check(char c);
void check(char c, char A[]);

using namespace std;

int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    check(num);
    
    char ch;
    cout << "\nEnter a character: ";
    cin >> ch;
    check(ch);
    
    char arr[100];
    char target;
    cout << "\nEnter a string (character array without spaces): ";
    cin >> arr;
    cout << "Enter a character to search for: ";
    cin >> target;
    check(target, arr);

    return 0;
}

void check(int n)
{
    if (n == 0)
    {
        cout << n << " is zero!\n";
        return;
    }
    if (n > 0)
    {
        cout << n << " is a positive number!\n";
        return;
    }
    cout << n << " is a negative number\n";
}

void check(char c)
{
    if(!isalpha(c))
    {
        cout << c << " is not an alphabet!\n";
        return;
    }

    // if('a' < c && c < 'z')
    if(islower(c))
    {
        cout << c << " is a lowercase letter!\n";
        return;
    }

    // if('A' < c && c < 'Z')
    if(isupper(c))
    {
        cout << c << " is an uppercase letter!\n";
        return;
    }
    
}

void check(char c, char A[])
{
    for(int i = 0; A[i]; i++)
    {
        if (c == A[i])
        {
            cout << c << " was found in the character array at index" << i << " \n";
            return;
        }
    }
    cout << c << " was not found in the character array!\n";
}