#include <iostream>
using namespace std;
int findMax(int a, int b, int c)
{
    int max = a;
    if (max == b && b == c)
    {
        return max;
    }
    else if (b >= max && b >= c)
    {
        return b;
    }
    else if (c >= max && c >= b)
    {
        return c;
    }
    else
    {
        return max;
    }
}
float findMax(float d, float e, float f)
{
    float max = d;
    if (max == e && e == f)
    {
        return max;
    }
    else if (e >= max && e >= f)
    {
        return e;
    }
    else if (f >= max && f >= e)
    {
        return f;
    }
    else
    {
        return max;
    }
}
int main()
{
    // Write a program using function overloading:
    // To find largest among three integers.
    // To find largest among three floating point numbers.
    cout << "\nProgram to find the maximum among three numbers" << endl;
    cout << "-----------------------------------------------" << endl;

    int x, y, z;
    float num1, num2, num3;

    cout << "Enter 3 integer numbers: ";
    cin >> x >> y >> z;
    cout << "Enter 3 float values: ";
    cin >> num1 >> num2 >> num3;

    cout << findMax(x, y, z) << " is the maximum among integer values!" << endl;
    cout << findMax(num1, num2, num3) << " is the maximum among float values!" << endl;
}