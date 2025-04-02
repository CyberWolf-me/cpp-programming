#include <iostream>
using namespace std;
int converting_time(int hours, int minutes, int seconds)
{
    minutes = hours * 60 + minutes + seconds / 60;
    return minutes;
}
int main()
{
    int hours;
    int minutes;
    int seconds;

    cout << "Enter the time:(x hours y minutes and z seconds): ";
    cin >> hours >> minutes >> seconds;

    cout << "All of them in minutes: " << converting_time(hours, minutes, seconds) << endl;
}