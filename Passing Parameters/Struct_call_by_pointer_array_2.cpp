#include <iostream>
using namespace std;
struct Rectangle
{
    int A[5];
    int sz;
};
void changelength(Rectangle *r1)
{
    for (int i = 0; i < r1->sz; i++)
    {
        r1->A[i] = i + 1;
    }
    r1->sz = 32;
}
int main()
{
    Rectangle r = {{5, 10, 324, 234, 32}, 5};
    changelength(&r);
    for (int k = 0; k < 5; k++)
    {
        cout << r.A[k] << endl;
    }
    cout << r.sz << endl;
    return 0;
}