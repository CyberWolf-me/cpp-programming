#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Enter the number: ";
    cin >> a;

    if (cin.fail())
    {
        cout << "Invalid input! Please enter a valid integer." << endl;
    }
    else if (a > 0)
    {
        cout << "Number is Positive!" << endl;
    }
    else if (a < 0)
    {
        cout << "Number is Negative!" << endl;
    }
    else
    {
        cout << "Number is 0!" << endl;
    }

    return 0;
}
