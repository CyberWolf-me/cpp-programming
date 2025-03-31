#include <iostream>
using namespace std;
int main()
{
    int number, sum = 0;

    cout << "Program to calculate the digits of a number" << endl;
    cout << "-------------------------------------------" << endl;

    cout << "Enter the number: " << endl;
    cin >> number;

    // digit= number%10;

    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }

    cout << "Sum of the digits of the number is: " << sum << endl;

    return 0;
}