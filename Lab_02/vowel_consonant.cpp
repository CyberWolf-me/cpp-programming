#include <iostream>
using namespace std;

int main()
{
    char l;

    cout << "Enter the character:  ";
    cin >> l;

    if (l == 'A' || l == 'E' || l == 'U' || l == 'O' || l == 'I' ||
        l == 'a' || l == 'e' || l == 'u' || l == 'o' || l == 'i')
    {
        cout << "The letter is a vowel" << endl;
    }

    else
    {
        cout << "The letter is either a consonant or an invalid data type" << endl;
    }

    return 0;
}
