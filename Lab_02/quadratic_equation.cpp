#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float a, b, c;
    float discriminant;

    cout << "Program to find the roots of a quadratic equation";
    cout << endl;

    cout << "Enter the coefficient of the quadratic equation(ax^2+bx+c=0): ";
    cin >> a >> b >> c;

    discriminant = b * b - 4 * a * c;
    if (a == 0)
    {
        cout << "It is not a quadratic equation!";
        if (b == 0)
        {
            cout << "There is no solution for this equation!";
        }
        else
        {
            cout << "The solution of this equation is: " << (-c) / b;
        }
    }
    else if (discriminant > 0)
    {
        cout << "The first root of the equaion is: " << (-b + sqrt(discriminant)) / (2 * a);
        cout << "The second root of the equaion is: " << (-b - sqrt(discriminant)) / (2 * a);
    }
    else if (discriminant == 0)
    {
        cout << "The only root of the equation is: " << (-b) / (2 * a);
    }
    else if (discriminant < 0)
    {
        cout << "There is no real solutions for this equation!";
    }
    else
    {
        cout << "Error:Invalid coeffienct input!";
    }

    return 0;
}