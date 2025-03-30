#include<iostream>
using namespace std;
int main() {
	float a, b, area;
	cout << "Enter the first side: ";
	cin >> a;
	cout << "Enter the second side: ";
	cin >> b;
	if (a > 0 && b > 0) {
		area = a * b;
		cout << "The area of the rectangle is: " << area;
	}
	else {
		cout << "The sides cannot be negative number!";
	}
	return 0;
}