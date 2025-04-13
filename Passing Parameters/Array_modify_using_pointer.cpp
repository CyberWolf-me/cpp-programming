#include <iostream>
using namespace std;
void modify(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
}
int main()
{
    int A[] = {2, 4, 6, 8, 10};
    int size = 5;
    cout << "Array Before: " << endl;
    for (int k = 0; k < size; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;
    cout << "Array After: " << endl;
    modify(A, size);
    for (int k = 0; k < size; k++)
    {
        cout << A[k] << " ";
    }

    return 0;
}