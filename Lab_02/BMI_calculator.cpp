#include <iostream>
using namespace std;
int main()
{
    float weight, height;
    float bmi;

    cout << "\nProgram to calculate BMI! " << endl;
    cout << endl;

    cout << "Enter your weight(kg) and height(m): ";
    cin >> weight >> height;

    bmi = weight / (height * height);

    if (bmi > 0 && bmi < 18.5)
    {
        cout << "You are an underweight ";
    }
    else if (bmi >= 18.5 && bmi < 24.9)
    {
        cout << "You have a normal weight ";
    }
    else if (bmi >= 24.5 && bmi < 29.9)
    {
        cout << "You are an overweight! ";
    }
    else if (bmi >= 29.9)
    {
        cout << "You have an obesity!(WORK on your body bro)";
    }
    else
    {
        cout << "Error";
    }

    return 0;
}