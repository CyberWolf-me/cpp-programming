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
    else if (m == n)
    {
        cout << "The sum is: " << m;
    }
    else if (m > n)
    {
        cout << "The sum is: " << 0;
    }
    else
    {
        cout << "The sum from " << m << " to " << n << " is: " << (n * (n + 1) * 0.5);
    }

    return 0;
}