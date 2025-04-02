#include <iostream>
using namespace std;
void swapping(int &a, int &b)
{
    int temp = 0;
    temp = a; // giving value of a to temp
    a = b;    // a getting value of b
    b = temp; // b getting value of temp
}
int main()
{
    cout << "\nProgram to swap values using functions" << endl;
    cout << "----------------------------------------" << endl;

    int x, y;

    cout << "Enter the values of a and b: ";
    cin >> x >> y;
    swapping(x, y);
    cout << "Swapped values: a=" << x << " and b=" << y << endl;
    return 0;
}