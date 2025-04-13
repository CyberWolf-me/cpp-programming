#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void changelength(Rectangle *r1)
{
    r1->length = 12;
    r1->breadth = 32;
}
int main()
{
    Rectangle r = {5, 10};
    Rectangle *ptr = &r;
    changelength(ptr);
    cout << ptr->breadth << endl;
    cout << ptr->length << endl;
    return 0;
}