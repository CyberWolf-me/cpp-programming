#include <iostream>
using namespace std;
int main()
{
    int num;

    cout << "\nProgram to print which day of the week it is" << endl;
    cout << "----------------------------------------------" << endl;

    cout << "Enter the number of the day in the week: ";
    cin >> num;

    switch (num)
    {
    case 1:
    {
        cout << "It is Monday!" << endl;
    }
    break;
    case 2:
    {
        cout << "It is Tuesday!" << endl;
    }
    break;
    case 3:
    {
        cout << "It is Wednesday!" << endl;
    }
    break;
    case 4:
    {
        cout << "It is Thursday!" << endl;
    }
    break;
    case 5:
    {
        cout << "It is Friday!" << endl;
    }
    break;
    case 6:
    {
        cout << "It is Saturday!" << endl;
    }
    break;
    case 7:
    {
        cout << "It is Sunday!" << endl;
    }
    break;
    }

    return 0;
}