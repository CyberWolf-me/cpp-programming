#include <iostream>
using namespace std;
int *fun(int n)
{
    int *a;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    return a;
}
int main()
{
    int *A, size = 5;
    A = fun(size);
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << endl;
    }
    delete[] A;
    return 0;
}