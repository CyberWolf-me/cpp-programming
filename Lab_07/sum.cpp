#include <iostream>
using namespace std;
int findSum(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    // else if (n == 1) no need bcs it is checking in if condition
    // {
    //     return 1;
    // }
    else
    {
        return n + findSum(n - 1);
    }
}
int main()
{
    // Find sum of natural numbers using recursion.
    cout << "\nProgram to calculate the sum of natural numbers using recursion" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    int n;
    cout << "Enter a natural number: ";
    cin >> n;

    // if (n == 0) better to handle it in Recursion ( returning 0 makes sense)
    // {
    //     cout << "Sum is: " << 0 << endl;
    // }

    if (n < 0)
    {
        cout << "Error: Invalid input!" << endl;
    }

    else
    {
        cout << "Sum of numbers from " << 1 << " to " << n << " is: " << findSum(n) << endl;
    }

    return 0;
}