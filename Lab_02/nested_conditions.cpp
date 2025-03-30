#include <iostream>
using namespace std;
int main()
{

    int age;
    char m;

    cout << "\nNested Conditions" << endl;
    cout << endl;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Do you have an membership status?(Y/n): ";
    cin >> m;

    if (m == 'Y' || m == 'y')
    {
        if (age >= 18)
        {
            cout << "You will get 20% discount" << endl;
        }
        else
        {
            cout << "We will char you fully!" << endl;
        }
    }

    else if (m == 'N' || m == 'n')
    {
        cout << "We will charge you fully!";
    }

    else
    {
        cout << "Error: Invalid membership input!";
    }

    return 0;
}