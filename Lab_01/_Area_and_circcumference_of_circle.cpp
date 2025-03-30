#include<iostream>
using namespace std;
int main() {
	double radius;
	double pi = 3.141592653;
	cout << "Enter the radius: ";
	cin >> radius;
	double area = radius * radius * pi;
	double circumference = 2 * pi * radius;
	cout << "The Area is: " << area << endl;
	cout << "The Circumference is: " << circumference << endl;
}