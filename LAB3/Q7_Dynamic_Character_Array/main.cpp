#include <iostream>

using namespace std;

char toLower(char c);
bool isVowel(char c);
bool isConsonant(char c);
bool isDigit(char c);


int main() {
    int n;
    cout << "Enter the max size of the string: ";
    cin >> n;

    // Dynamically allocate memory for a character array
    char* str = new char[n + 1]; // +1 because of '\0'
    
    cin.ignore();
    cout << "Enter a string: ";
    cin.getline(str, n + 1); //getline takes, where to store and its size

    int vowels = 0, consonants = 0, digits = 0, spaces = 0, characters = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (isVowel(c))
        {
            vowels++;
        }
        else if (isDigit(c))
        {
            digits++;
        }

        else if (isConsonant(c))
        {
            consonants++;
        }
        else if (c == ' ')
        {
            spaces++;
        }
        else 
        {
            characters++;
        }
    }


    cout << "\n--- String Analysis ---\n";
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Special Characters: " << characters << endl;

    // Release memory
    delete[] str;
    str = nullptr;

    return 0;
}


char toLower(char c)
{
    if (('A' <= c) and (c <= 'Z'))
    {
        return c + ('a' - 'A');
    }
    else
    {
        return c;
    } 
}

bool isVowel(char c)
{
    c = toLower(c);
    string vowels = "aeiou";
    for (char i : vowels)
    {
        if (i == c)
            return true;
    }
    return false;
}


bool isDigit(char c)
{
    string digits = "0123456789";
    for (char i : digits)
    {
        if (i == c)
            return true;
    }
    return false;
}

bool isConsonant(char c)
{
    c = toLower(c);
    string consonants = "bcdfghjklmnpqrstvwxyz";
    for (char i : consonants)
    {
        if (i == c)
            return true;
    }
    return false;
}

/* ASCII TABLE
The decimal set:

       0 nul    1 soh    2 stx    3 etx    4 eot    5 enq    6 ack    7 bel
       8 bs     9 ht    10 nl    11 vt    12 np    13 cr    14 so    15 si
      16 dle   17 dc1   18 dc2   19 dc3   20 dc4   21 nak   22 syn   23 etb
      24 can   25 em    26 sub   27 esc   28 fs    29 gs    30 rs    31 us
      32 sp    33  !    34  "    35  #    36  $    37  %    38  &    39  '
      40  (    41  )    42  *    43  +    44  ,    45  -    46  .    47  /
      48  0    49  1    50  2    51  3    52  4    53  5    54  6    55  7
      56  8    57  9    58  :    59  ;    60  <    61  =    62  >    63  ?
      64  @    65  A    66  B    67  C    68  D    69  E    70  F    71  G
      72  H    73  I    74  J    75  K    76  L    77  M    78  N    79  O
      80  P    81  Q    82  R    83  S    84  T    85  U    86  V    87  W
      88  X    89  Y    90  Z    91  [    92  \    93  ]    94  ^    95  _
      96  `    97  a    98  b    99  c   100  d   101  e   102  f   103  g
     104  h   105  i   106  j   107  k   108  l   109  m   110  n   111  o
     112  p   113  q   114  r   115  s   116  t   117  u   118  v   119  w
     120  x   121  y   122  z   123  {   124  |   125  }   126  ~   127 del

*/
