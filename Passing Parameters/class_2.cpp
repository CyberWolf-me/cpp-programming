#include <iostream>
using namespace std;
class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle() : length(0), breadth(0) {}
    Rectangle(int l, int b);
    void initialise(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area();
    int perimeter();
    void display()
    {
        cout << "Perimeter is: " << perimeter() << endl;
        cout << "Area is: " << area() << endl;
    }
};
Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}
int Rectangle::area()
{
    return length * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}
int main()
{
    Rectangle r;
    int l, b;
    cout << "Enter the length and breadth: ";
    cin >> l >> b;
    r.initialise(l, b);
    r.display();
}