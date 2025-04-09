#include <iostream>
#include <cmath>
using namespace std;

double Area(double radius)
{
    return pow(radius, 2) * 3.14; // Area of Circle
}

double Area(double a, double b)
{
    return a * b; // Area of Rectangle
}

double Area(double x, double y, double z)
{
    double p, area;
    p = (x + y + z) / 2;
    area = sqrt((p * (p - x) * (p - y) * (p - z)));
    return area;
}

float Area(float x)
{
    return pow(x, 2); // Area of Square (Changed to double)
}
int main()
{
    cout << "\nProgram to calculate Areas of shapes" << endl;
    cout << "---------------------------------------" << endl;

    double radius, siderec1, siderec2, x, y, z;
    float side;

    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Enter the 2 sides of the rectangle: ";
    cin >> siderec1 >> siderec2;
    cout << "Enter the sides of the triangle: ";
    cin >> x >> y >> z;
    cout << "Enter the side of the square: ";
    cin >> side;

    cout << "Area of the circle: " << Area(radius) << endl;
    cout << "Area of the rectangle: " << Area(siderec1, siderec2) << endl;
    cout << "Area of the triangle: " << Area(x, y, z) << endl;
    cout << "Area of the square: " << Area(side) << endl;

    return 0;
}
