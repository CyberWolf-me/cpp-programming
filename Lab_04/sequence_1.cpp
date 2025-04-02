#include <iostream>
using namespace std;
int main()
{
    // *
    // **
    // ***
    // ****
    // *****

    for (int i = 1; i <= 5; i++) // for controlling that there will be 5 rows
    {
        for (int k = 1; k <= i; k++) // for number of stars
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}