#include <iostream>
using namespace std;
int findGCD(int x, int y)
{
    int remainder = 0;
    if (x <= 0 || y <= 0)
    {
        return 0;
    }
    else if (x > y)
    {
        remainder = x % y;
        if (remainder == 0)
        {
            return y;
        }
        else
        {
            return findGCD(y, remainder);
        }
    }
    else
    {
        remainder = y % x;
        if (remainder == 0)
        {
            return x;
        }
        else
        {
            return findGCD(x, remainder);
        }
    }
}
int main()
{

    // Start with two integers, 'a' and 'b' (where a > b).
    // Divide 'a' by 'b' and find the remainder 'r'.
    // If 'r' is 0, then 'b' is the GCD.
    // If 'r' is not 0, replace 'a' with 'b' and 'b' with 'r', and repeat step 2.
    // Continue this process until the remainder is 0, at which point the divisor is the GCD.

    cout << "\nProgram to find G.C.D for two integers using recursion." << endl;
    cout << "---------------------------------------------------------" << endl;

    int x, y;
    cout << "Enter 2 numbers: ";
    cin >> x >> y;
    if (x <= 0 || y <= 0)
    {
        cout << "Error: Invalid input!" << endl;
    }
    else
    {
        cout << "The GCD of " << x << " and " << y << " is: " << findGCD(x, y) << endl;
    }

    return 0;
}