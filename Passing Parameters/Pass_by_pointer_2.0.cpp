#include <iostream>
using namespace std;
void change(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int c = 10, d = 5;
    int *x = &c, *y = &d;
    change(x, y);
    cout << *x << endl;
    cout << *y << endl;

    return 0;
}