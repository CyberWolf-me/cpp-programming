#include <iostream>
using namespace std;
class Rectangular
{
private:
    int length;
    int breadth;

public:
    Rectangular(int l, int b) : length(l), breadth(b)
    {
    }
    int area()
    {
        return length * breadth;
    }
    void changelength(int l)
    {
        length = l;
    }
};
int main()
{
    Rectangular r(10, 5);
    r.changelength(7);
    cout << r.area() << endl;

    return 0;
}