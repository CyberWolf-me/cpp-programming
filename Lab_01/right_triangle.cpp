#include<iostream>
#include<math.h>
using namespace std;
float area(float adj1, float adj2, float hyp) {
	float area = adj1 * adj2 * 0.5;
	return area;
}
int main() {
	float adj1, adj2, hyp=0;
	char a;
	cout << "Enter the first Adjacent: ";
	cin >> adj1;
	cout<< "Enter the second Adjacent: ";
	cin >> adj2;
	cout << "Do you want to check if the triangle has the right angle?(If yes choose: '+', if no choose: '-' ";
	cin >> a;
	switch(a){
	case '+': {
		cout << "Enter the hypotenuse:(It is just for checking if the triangle has a right angle: ";
		cin >> hyp;
		if ((adj1 * adj1 + adj2 * adj2) == hyp * hyp) {
			cout << "The triangle has the right angle: " << endl;
			cout << "The Area is: " << area(adj1, adj2, hyp)<<endl;
		}
		else {
			cout << "The triangle does not have the right angle and the area can be wrong!";
		}
	break;
	}
	case '-': {
		cout << "Here is the Area: "<< area(adj1, adj2, hyp);
	break;
	}
	}
	return 0;
	
}