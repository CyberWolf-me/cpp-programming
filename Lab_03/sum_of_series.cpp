#include <iostream>
using namespace std;

int main()
{
    int k;
    double sum = 0;

    cout << "\nProgram to calculate the sum of series from 1 to 1/k" << endl;
    cout << "-----------------------------------------------------" << endl;

    // Series from 1 to k(or infinity);
    // should calculate the sum
    // how?
    // we know where it starts(1) and where it ends(k)-->> meaning we can use for loop
    // but how to calculate sum of 1/k?
    // sum +=(1/k)

    cout << "Enter k: ";
    cin >> k;

    if (k <= 0)
    {
        cout << "Error: k must be a positive integer!";
        return 0;
    }

    for (int i = 1; i <= k; i++)
    {
        sum += (1.0 / i);
    }

    cout << "The sum of the series from 1 to 1/" << k << " is: " << sum;
    return 0;
}
