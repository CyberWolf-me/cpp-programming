#include <iostream>
using namespace std;
int main()
{
    float a;
    float b;
    char c;

    cout << "\nProgram to calculate simple arithmetic problems";
    cout << endl;

    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    cout << "Which operator do you want to use(+,-,*,/): ";
    cin >> c;

    switch (c)
    {
    case '+':
    {
        cout << "Addition: " << a << "+" << b << " = " << a + b;
        break;
    }
    case '-':
    {
        cout << "Subtraction: " << a << "-" << b << " = " << a - b;
        break;
    }
    case '/':
    {
        if (b == 0)
        {
            cout << "Error: Division by zero is not allowed!" << endl;
        }
        else
        {
            cout << "Division: " << a << "/" << b << " = " << a / b << endl;
            ;
        }
        break;
    }
    case '*':
    {
        cout << "Multiplication: " << a << "*" << b << " = " << a * b << endl;
        break;
    }
    default:
    {
        cout << "Invalid operator!" << endl;
    }
    }
    return 0;
}