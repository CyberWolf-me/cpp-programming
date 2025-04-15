#include <iostream>
using namespace std;
template <class T>
class Arithmetic
{
private:
    int a;
    int b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};
template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}
template <class T>
T Arithmetic<T>::add()
{
    return a + b;
}
template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
}

int main()
{
    Arithmetic<int> r1(10, 5);
    cout << "Add: " << r1.add() << endl;
    cout << "Subtract: " << r1.sub() << endl;
    Arithmetic<float> r2(1.2, 5.2);
    cout << "Add: " << r2.add() << endl;
    cout << "Subtract: " << r2.sub() << endl;

    system("pause");
    return 0;
}