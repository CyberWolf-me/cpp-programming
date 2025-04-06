#include <iostream>
using namespace std;
int findfibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return findfibo(n - 1) + findfibo(n - 2);
    }
}
int main()
{
    cout << "\nProgram to print out fibonacci number" << endl;
    cout << "---------------------------------------" << endl;

    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (n < 0 || cin.fail())
    {
        cout << "Error: Invalid input!" << endl;
    }
    else
    {
        cout << findfibo(n);
    }

    return 0;
}