#include <iostream>
using namespace std;
int main()
{
    int year;

    cout << "\nProgram to check if it is a leap year or not" << endl;
    cout << "Enter the year: ";
    cin >> year;

    // Leap Year -> can be divided by 4 and 400 but not by 100
    // still a leap year if it can be divisible by 400!

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        cout << year << " is a leap year!" << endl;
    }
    else
    {
        cout << year << " is not a leap year!";
    }

    return 0;
}