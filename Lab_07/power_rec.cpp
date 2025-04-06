#include <iostream>
using namespace std;

double calculatePower(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y > 0)
    {
        return x * calculatePower(x, y - 1);
    }
    else
    {
        return 1.0 / calculatePower(x, -y); // negative exponent // good point
    }
}

int main()
{
    cout << "\nProgram to calculate x^y (power) using recursion " << endl;
    cout << "------------------------------------------------------" << endl;

    int a, b;
    cout << "Enter the number: ";
    cin >> a;
    cout << "To which power do you want to raise?: ";
    cin >> b;

    // special cases
    if (a == 0 && b == 0)
    {
        cout << "Error: 0^0 is undefined!" << endl;
    }
    else
    {
        cout << a << "^" << b << " is: " << calculatePower(a, b) << endl;
    }

    return 0;
}
