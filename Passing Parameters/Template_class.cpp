#include <iostream>
using namespace std;
template <class T>
class Arithmetic
{
private:
    int a;
    int b;

public:
    Arithmetic(T a, T b) : a(a), b(b)
    {
    }
    T add()
    {
        return a + b;
    }
    T sub()
    {
        return a - b
    }
};
int main()
{
    Arithmetic<int> r1(10, 5);
    cout << "Add: " << r1.add();
    cout << "Subtract: " << r1.sub();
    Arithmetic<float> r2(1.2, 5.2);
    cout << "Add: " << r2.add();
    cout << "Subtract: " << r2.sub();

    return 0;
}