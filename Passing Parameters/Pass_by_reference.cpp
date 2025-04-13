#include <iostream>
using namespace std;
void lala(int &a, int &b)
{
    a = 5;
    b = 10;
}
int main()
{
    int x, y;
    x = 432;
    y = 123;
    lala(x, y);
    cout << x << endl;
    cout << y << endl;

    return 0;
}