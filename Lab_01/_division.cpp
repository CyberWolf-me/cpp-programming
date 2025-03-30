#include <iostream>
using namespace std;
int main() {
	int number1;
	int number2;
	int quotient;
	int remainder;
	cout << "Enter the first number: ";
	cin >> number1;
	cout << "Enter the second number: ";
	cin >> number2;
	if (number1 >= number2) {
		cout << "The quiotient is: " << number1 / number2 << endl;
		cout << "The remainder is: " << number1 % number2;
	}
	if (number2 > number1) {
		cout << "The quiotient is: " << number2 / number1 << endl;
		cout << "The remainder is: " << number2 % number1;
	}
}
