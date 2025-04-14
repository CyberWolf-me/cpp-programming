#include <iostream>
using namespace std;
class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle() : length(0), breadth(0)
    {
    }
    Rectangle(int l, int b) : length(l), breadth(b)
    {
    }
    int area()
    {
        return breadth * length;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
    void setLength(int l)
    {
        length = l;
    }
    int getLength()
    {
        return length;
    }
    void setBreadth(int b)
    {
        breadth = b;
    }
    int getBreadth()
    {
        return breadth;
    }
    void display()
    {
        cout << "Area is: " << area() << endl;
        cout << "Perimeter is: " << perimeter() << endl;
    }
};
int main()
{
    Rectangle r(10, 5);
    r.setBreadth(40);
    r.setLength(50);
    r.display();
}