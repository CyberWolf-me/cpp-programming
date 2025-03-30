#include <iostream>
using namespace std;
int main()
{
    int salary;

    cout << "\nTax Calculator" << endl;
    cout << endl;

    cout << "Enter your salary: ";
    cin >> salary;

    if (salary <= 1500)
    {
        cout << "There are no taxes for you!";
    }
    else if (salary <= 3000)
    {
        cout << "There is 10% tax for you which will be: " << (salary * 10) / 100 << "$";
    }
    else if (salary < 5000)
    {
        cout << "There is 20% tax for you which will be: " << (salary * 20) / 100 << "$";
    }
    else if (salary >= 5000)
    {
        cout << "There is 30% tax for you which will be: " << (salary * 30) / 100 << "$";
    }
    else
    {
        cout << "Error: Invalid salary input!";
    }

    return 0;
}