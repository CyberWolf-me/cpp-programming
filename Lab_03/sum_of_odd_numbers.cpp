#include <iostream>
using namespace std;
int main()
{
    int k, sum = 0;

    cout << "\nProgram to calculate the sum of odd numbers from 1 to k" << endl;
    cout << "----------------------------------------------------------" << endl;

    // Should calculate from 1 to k(odd numbers);
    // we know where it starts and where it ends ;
    // how to calculate sum of odd numbers??
    // here is how: sum+=i -->> we want from 1 to k same thing;
    // we use for loop;

    cout << "Enter the value of the K: ";
    cin >> k;

    if (k <= 0)
    {
        cout << "Error: K cannot be negative or 0!";
        return 0;
    }

    for (int i = 1; i <= k; i += 2)
    {
        sum += i;
    }

    cout << "The sum of the odd numbers from " << 1 << " to " << k << " is: " << sum << endl;

    return 0;
}