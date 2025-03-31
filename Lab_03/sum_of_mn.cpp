#include <iostream>
using namespace std;
int main()
{
    int m, n, sum = 0;

    cout << "\nProgram to calculate sum of numbers from M to N" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Enter M and N,respectively: ";
    cin >> m >> n;

    if (cin.fail())
    {
        cout << "Error: Invalid data input!";
    }
    else if (m > n)
    {
        cout << "Error: M should be less or equal to N!" << 0;
    }
    else if (m == n)
    {
        cout << "The sum is: " << m;
    }
    else
    {
        sum = (n * (n + 1) / 2) - ((m - 1) * m / 2);
        cout << "The sum from " << m << " to " << n << " is: " << sum;
    }

    return 0;
}