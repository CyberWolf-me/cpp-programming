#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    cout << "Enter the 3 numbers: ";
    cin >> a >> b >> c;

    if (a == b && b == c)
    {
        cout << "All numbers are equal." << endl;
    }
    else if (a >= b && a >= c)
    {
        cout << "The greatest number is " << a << "." << endl;
    }
    else if (b >= a && b >= c)
    {
        cout << "The greatest number is " << b << "." << endl;
    }
    else
    {
        cout << "The greatest number is " << c << "." << endl;
    }

    return 0;
}
