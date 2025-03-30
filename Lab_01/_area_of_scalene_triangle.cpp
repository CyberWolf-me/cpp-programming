#include<iostream>
#include<math.h>
using namespace std;
int main() {
	double side1, side2, side3, area, p;
	cout << "Enter the sides: ";
	cin >> side1 >> side2 >> side3;
	if (side1 > 0 && side2 > 0 && side3 > 0) {
		if (side1 < side2 + side3 && side2 < side1 + side3 && side3 < side1 + side2) {
			p = (side1 + side2 + side3) / 2;
		    area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
			cout << "The Area of the triangle is: " << area;
		}
		else {
			cout << "Try other values for the sides of triangle";
		}
	}
	else {
		cout << "Sides cannot be negative numbers!";
	}
	return 0;
}