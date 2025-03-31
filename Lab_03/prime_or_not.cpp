#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;

    cout << "\nProgram to check if the number is prime or not" << endl;
    cout << "------------------------------------------------" << endl;

    // prime == is a number that has only 2 divisors(1 or itself)
    // divisors== should be checked if it is prime or not
    // how do we check == using for loop
    // first prime number== 2 last -->> till sqrt(prime) optimized version
    // so we need to check for the divisors from 2 to sqrt(2) should  stop when
    // divisor is found-->>using what-->>bool if(has divisor number=false) and should stop by break;

    cout << "Enter the number: ";
    cin >> num;

    if (num < 2)
    {
        cout << "The number is not a prime number;";
        return 0; // early exit :)
    }

    bool isPrime = true;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            // updates the value of isPrime;
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << "It is a prime number!";
    }
    else
    {
        cout << "It is not a prime number!";
    }

    return 0;
}