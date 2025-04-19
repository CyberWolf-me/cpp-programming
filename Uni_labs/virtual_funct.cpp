// U2410042
// Axmedov Feruzbek
// Lab#7#include<iostream>
#include <iostream>
#include <string>
using namespace std;
// Classes
class Person
{
protected:
	string Name;
	int Age;
	char Gender;

public:
	void setData(string n, int a, char g)
	{
		Name = n;
		Age = a;
		Gender = g;
	}
	void showData()
	{
		cout << "Name: " << Name << endl;
		cout << "Age: " << Age << endl;
		cout << "Gender: " << Gender << endl;
	}
};
class Student : virtual public Person
{
private:
	int IdNumber;
	string Subject;
	int Grade;

public:
	void setStudent(int id, string sub, int gr)
	{
		IdNumber = id;
		Subject = sub;
		Grade = gr;
	}
	void showStudent()
	{
		cout << "Id Number: U" << IdNumber << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Grade: " << Grade << endl;
	}
};
class Teacher : virtual public Person
{
private:
	string CourseInfo;

public:
	void setTeacher(string course)
	{
		CourseInfo = course;
	}
	void showTeacher()
	{
		cout << "Course Info: " << CourseInfo;
	}
};
class ECLASS : public Student, public Teacher
{
public:
	void ShowStudentInfo()
	{
		showData();
		showStudent();
	}
	void ShowTeacherInfo()
	{
		showData();
		showTeacher();
	}
};
int main()
{
	ECLASS student1;
	student1.setData("Axmedov Feruzbek", 18, 'M');
	student1.setStudent(2410042, "OOP", 30);
	student1.ShowStudentInfo();
	cout << "----------------------------------------" << endl;
	ECLASS teacher1;
	teacher1.setTeacher("Object Oriented Programming");
	teacher1.setData("Suvanov Sharof", 33, 'M');
	teacher1.ShowTeacherInfo();

	return 0;
}