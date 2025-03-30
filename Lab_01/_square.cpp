#include<iostream>
using namespace std;
int main() {
	float side, area;
	cout << "Enter the side of the square: ";
	cin >> side;
	if (side > 0) {
		area = side * side;
		cout << "The area is: " << area;
	}
	else {
		cout << "The side cannot be negative!";
	}
}