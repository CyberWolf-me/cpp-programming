#include <iostream>
using namespace std;
int calculatePower(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * calculatePower(x, y - 1);
    }
}
int main()
{
    // Calculate the x^y (power) using recursion.
    cout << "\nProgram to calculate the x^y (power) using recursion " << endl;
    cout << "------------------------------------------------------" << endl;

    int a, b;
    cout << "Enter the number: ";
    cin >> a;
    cout << "To which power do you want to raise?: ";
    cin >> b;

    cout << a << "^" << b << " is: " << calculatePower(a, b) << endl;
}