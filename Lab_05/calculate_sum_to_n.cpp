#include <iostream>
using namespace std;
int calculate_sum(int n)
{
    return (n * (n + 1) / 2);
}
int main()
{
    cout << "\nProgram to sum the series up to n (Input n)" << endl;
    cout << "---------------------------------------------" << endl;

    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    if (n > 0)
    {
        cout << "All the sum of series up to n is: " << calculate_sum(n);
    }
    else if (n == 0)
    {
        cout << "Sum is: " << 0;
    }
    else
    {
        cout << "Invalid Input!";
    }
    return 0;
}