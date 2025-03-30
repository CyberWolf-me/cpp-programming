#include<iostream>
using namespace std;
int main() {
	float num1, num2, temp=0;
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	temp = num1;
	num1 = num2;
	num2 = temp;
	
	cout << "The first number before swapping: " << num2 << " after swapping: " << num1 << endl;
	cout << "The second number before swapping: " << num1 << " after swapping: " << num2;
}