#include <iostream>
#include <limits>
using namespace std;
long long findFactorial(long n)

{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * findFactorial(n - 1);
    }
}
int main()
{
    cout << "\nProgram to calculate the factorial" << endl;
    cout << "------------------------------------" << endl;

    int n;
    cout << "Enter the factorial number: ";
    cin >> n;

    if (n < 0 || cin.fail())
    {
        cout << "Error: Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        cout << n << "! factorial is: " << findFactorial(n) << endl;
    }

    return 0;
}