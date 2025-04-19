// Axmedov Feruzbek
// U2410042
// Lab#8
#include <iostream>
#include <string>
using namespace std;
class Hospital
{
protected:
	int ID;
	string Name;
	int Age;
	char Gender;

public:
	Hospital(int i, string n, int a, char g) : ID(i), Name(n), Age(a), Gender(g)
	{
	}
	void virtual Display()
	{
		cout << "Id: " << ID << endl;
		cout << "Name: " << Name << endl;
		cout << "Age: " << Age << endl;
		cout << "Gender: " << Gender << endl;
	}
};
class Doctor : public Hospital
{
private:
	string Department;
	string cons_day;
	int cons_hours;
	string surgery_day;

public:
	Doctor(string dep, string day, int hours, string surgery, int i, string n, int a, char g) : Department(dep), cons_day(day), cons_hours(hours), surgery_day(surgery), Hospital(i, n, a, g)
	{
	}
	void Display()
	{
		cout << "Department: " << Department << endl;
		cout << "Cons_Day: " << cons_day << endl;
		cout << "Cons_Hours: " << cons_hours << endl;
		cout << "Surgery_Day: " << surgery_day << endl;
		Hospital::Display();
	}
};
class Patient : public Hospital
{
private:
	string Med_History;

public:
	Patient(string Med, int i, string n, int a, char g) : Med_History(Med), Hospital(i, n, a, g)
	{
	}

	void Display()
	{
		cout << "Med History: " << Med_History << endl;
		Hospital::Display();
	}
};
int main()
{
	Hospital *Hptr[4];
	Doctor d1("Nursery Department", "Monday", 8, "Facial Surgery", 1212, "Doctor 1", 53, 'M');
	Doctor d2("Surgery Department", "Tuesday", 7, "Heart Surgery", 3342, "Doctor 2", 41, 'F');
	Patient p1("Have Record ", 3232, "Patient 1", 61, 'M');
	Patient p2("No history", 2321, "Patient 2", 51, 'F');
	Hptr[0] = &d1;
	Hptr[1] = &d2;
	Hptr[2] = &p1;
	Hptr[3] = &p2;
	cout << "...........Hospital Details.........." << endl;
	cout << "................Doctor..............." << endl;
	Hptr[0]->Display();
	cout << "................Patient.............." << endl;
	Hptr[2]->Display();
	cout << "................Doctor..............." << endl;
	Hptr[1]->Display();
	cout << "................Patient.............." << endl;
	Hptr[3]->Display();

	return 0;
}
