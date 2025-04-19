#include <iostream>
#include <string>
using namespace std;
// Base Class
class Student
{
protected:
    int ID;
    string Name;
    string School;
    int GroupNumber;

public:
    Student()
    {
        ID = 0;
        Name = "Unknown";
        School = "Unknown";
        GroupNumber = 0;
    }
    Student(int i, string n, string s, int g)
    {
        ID = i;
        Name = n;
        School = s;
        GroupNumber = g;
    }
};
// Dervied Class
// Test
class Test : public Student
{
protected:
    int Physics;
    int OOP;
    int English;

public:
    Test()
    {
        Physics = 0;
        OOP = 0;
        English = 0;
    }
    Test(int i, string n, string s, int g, int p, int o, int e)
        : Student(i, n, s, g)
    {
        Physics = p;
        OOP = o;
        English = e;
    }
};
// Derived Class 2
// Result
class Result : public Test
{
private:
    int Total;
    float GPI;

public:
    Result()
    {
        Total = 0;
        GPI = 0;
    };
    Result(int i, string n, string s, int g, int p, int o, int e)
        : Test(i, n, s, g, p, o, e)
    {
        TotalMark();
        Gpi();
    }
    void TotalMark()
    {
        Total = Physics + OOP + English;
    }
    void Gpi()
    {
        GPI = float(Total) / 3;
    }
    // Display Function
    void Display()
    {
        cout << "ID of the Student: " << ID << endl;
        cout << "Name of the Student: " << Name << endl;
        cout << "School Name: " << School << endl;
        cout << "Group Number: " << GroupNumber << endl;
        cout << "Mark from Physics: " << Physics << endl;
        cout << "Mark from OOP: " << OOP << endl;
        cout << "Mark from English: " << English << endl;
        cout << "Total Marks: " << Total << endl;
        cout << "GPI: " << GPI << endl
             << endl;
    }
};
int main()
{
    Result result1(1, "Axmedov Feruzbek", "School-1", 110, 77, 25, 30);
    Result result2(2, "Student 2", "School-2", 140, 45, 15, 24);

    result1.Display();
    result2.Display();

    return 0;
}
