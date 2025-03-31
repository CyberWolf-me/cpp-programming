#include <iostream>
using namespace std;
int main()
{
    char a;

    cout << "\nProgram to check if the character is an alphabet" << endl;
    cout << endl;

    cout << "Enter the character: ";
    cin >> a;

       if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
    {
        cout << "The character is an alphabet!" << endl;
    }
    else
    {
        cout << "The character is not an alphabet!" << endl;
    }
    return 0;
}