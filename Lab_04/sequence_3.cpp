#include <iostream>
using namespace std;
int main()
{
    // *****
    // ****
    // ***
    // **
    // *
    // 5 rows
    // outer row from 5 to 1 stars
    // inner loop for space from 1 to 5

    for (int i = 1; i <= 5; i++)
    {
        for (int k = 1; k <= 5 - i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}