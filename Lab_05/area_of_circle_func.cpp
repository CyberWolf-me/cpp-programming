#include <iostream>
#include <cmath>
using namespace std;
float findArea(float r);
int main()
{
    cout << "\nProgram to calculate area of a circle using functions." << endl;
    cout << "-------------------------------------------------------" << endl;

    float radius;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    if (radius > 0)
    {
        cout << "The area of the circle is: " << findArea(radius) << endl;
        return 0;
    }
    else
    {
        cout << "Invalid radius!" << endl;
    }

    return 0;
}

float findArea(float r)
{
    return pow(r, 2) * 3.14;
}