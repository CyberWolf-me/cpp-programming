#include<iostream>
#include<math.h>
using namespace std;
int main() {
	float area, side;
	cout << "Enter the value of the side: ";
	cin >> side;
	if (side > 0) {
		area = sqrt(3) * side * side*0.25;
		cout << "The Area is: " << area;
	}
	else {
		cout << "Sides cannot be negative number! ";
	}
	return 0;
}