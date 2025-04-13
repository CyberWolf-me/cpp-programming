#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // Write a program to find average of array elements.

    cout << "\nProgram to calculate the average of the array elements" << endl;
    cout << "-----------------------------------------------" << endl;

    int size;
    double sum = 0;
    cout << "Enter the array size: ";
    cin >> size;
    if (size <= 0)
    {
        cout << "Size cannot be 0 or negative number! " << endl;
        return 1;
    }

    double *arr1 = new double[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
        sum += arr1[i];
    }
    double avg = sum / size;
    cout << "The average is: " << avg << endl;
    delete[] arr1;
    return 0;
}