#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 1, sum = 0;

    cout << "\nProgram to print the fibonacci numbers to 100" << endl;
    cout << "-----------------------------------------------" << endl;

    cout << a << endl;
    cout << b << endl;
    while (b <= 100)
    {
        sum = a + b;
        a = b;
        b = sum;
        cout << sum << endl;
    }

    return 0;
}