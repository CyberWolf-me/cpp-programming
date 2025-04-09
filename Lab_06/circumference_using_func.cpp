#include <iostream>
using namespace std;
float circumference(float r)
{
    return 2 * 3.141592653 * r;
}
int circumference(int s1, int s2)
{
    return 2 * (s1 + s2);
}
double circumference(double s)
{
    return 4 * s;
}
double circumference(double a, double b, double c)
{
    return a + b + c;
}
int main()
{
    float radius;
    int s1, s2;
    double a, b, c, s;
    cout << "\nProgram to print out circumference of simple shapes, using functions" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    cout << "Enter the value of radius of the circle: ";
    cin >> radius;
    cout << "Enter the value of the 2 sides of the rectangle: ";
    cin >> s1 >> s2;
    cout << "Enter the value of the side of the square: ";
    cin >> s;
    cout << "Enter the value of the 3 sides of the triangle:  ";
    cin >> a >> b >> c;

    if (radius >= 0)
    {
        cout << "Circumference of Circle is: " << circumference(radius) << endl;
    }
    else
    {
        cout << "Error : Radius cannot be negative number!" << endl;
    }
    if (s1 >= 0 && s2 >= 0)
    {
        cout << "Circumference of Rectangle is: " << circumference(s1, s2) << endl;
    }
    else
    {
        cout << "Error : Sides cannot be negative number!" << endl;
    }
    if (s >= 0)
    {
        cout << "Circumference of Square is: " << circumference(s) << endl;
    }
    else
    {
        cout << "Error : Side cannot be negative number!" << endl;
    }

    if (a >= 0 && b >= 0 && c >= 0)
    {
        cout << "Circumference of Triangle is: " << circumference(s1, s2) << endl;
    }
    else
    {
        cout << "Error : Sides cannot be negative number!" << endl;
    }

    return 0;
}