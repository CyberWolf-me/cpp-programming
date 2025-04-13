#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

	char stfs[10];
	cout << "Enter 10 elements for string array: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> stfs[i];
	}
	for (int k = 0; k < 10; k++)
	{
		cout << setw(7) << k << setw(13) << "Value: " << stfs[k] << endl;
	}

	return 0;
}