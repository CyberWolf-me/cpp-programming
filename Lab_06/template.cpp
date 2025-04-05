#include <iostream>
using namespace std;
template <typename T>
T findMax(T a, T b, T c)
{
    T max = a;
    if (max == b && b == c)
    {
        max = b;
    }
    else if (b >= max && b >= c)
    {
        max = b;
    }
    else if (c >= max && c >= b)
    {
        max = c;
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
    return 0;
}