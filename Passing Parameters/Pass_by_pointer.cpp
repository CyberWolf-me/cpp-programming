#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a = 10, b = 15;
    swap(&a, &b);
    cout << "A is now: " << a << endl;
    cout << "B is now: " << b << endl;

    return 0;
}