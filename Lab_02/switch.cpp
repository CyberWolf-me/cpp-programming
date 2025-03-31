#include <iostream>
using namespace std;
int main()
{
    int a;

    cout << "Program to print out week days" << endl;
    cout << endl;

    cout << "Enter the number of the day in the week: ";
    cin >> a;

    switch (a)
    {
    case 1:
    {
        cout << "It is Monday!";
        break;
    }
    case 2:
    {
        cout << "It is Tuesday!";
        break;
    }
    case 3:
    {
        cout << "It is Wednesday!";
        break;
    }
    case 4:
    {
        cout << "It is Thursday!";
        break;
    }
    case 5:
    {
        cout << "It is Friday!";
        break;
    }
    case 6:
    {
        cout << "It is Saturday!";
        break;
    }
    case 7:
    {
        cout << "It is Sunday!";
        break;
    }
    default:
    {
        cout << "Error: invalid input for day number!";
    }
    }
}