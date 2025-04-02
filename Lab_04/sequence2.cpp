#include <iostream>
using namespace std;
int main()
{
    //     *
    //    **
    //   ***
    //  ****
    // *****
    // outer loop from  5 rows
    // inner loop for space?
    //( in first row 4 space 1 star)
    //( in second row 3 space 2 star)
    //( in third row 2 space 3 star)
    // first inner loop for space from outer 5 - j
    // second inner for stars: from 1 to i;

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
