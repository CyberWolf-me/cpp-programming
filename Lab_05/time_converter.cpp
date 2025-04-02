#include <iostream>
using namespace std;
double converting_time(double hours, double minutes, double seconds)
{
    minutes = (hours * 60) + minutes + (seconds / 60);
    return minutes;
}
int main()
{
    double hours, minutes, seconds;

    cout << "Enter the time: " << endl;
    cout << "Hours: ";
    cin >> hours;
    cout << "Minutes: ";
    cin >> minutes;
    cout << "Seconds: ";
    cin >> seconds;

    if (hours >= 0 && minutes >= 0 && seconds >= 0)
    {
        cout << "All of them in minutes: " << converting_time(hours, minutes, seconds) << endl;
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }

    return 0;
}