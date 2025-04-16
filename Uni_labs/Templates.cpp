// Feruzbek Axmedov
// U2410042
// Lab#9
#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string Name;
    int Age;
    char Gender;

public:
    Person(string n, int a, char g) : Name(n), Age(a), Gender(g)
    {
    }
    void virtual Display()
    {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << Gender << endl;
    }
};
template <class T>
class Student : public Person
{
private:
    T ID_Number;

public:
    Student(T id, string n, int a, int g) : ID_Number(id), Person(n, a, g)
    {
    }
    void Display()
    {
        Person::Display();
        cout << "ID Number: " << ID_Number << endl;
    }
};
int main()
{
    cout << "--------------Student 1 --------------" << endl;
    Student<string> s1("U2410042", "Axmedov Feruzbek", 18, 'M');
    s1.Display();
    cout << "--------------Student 2 --------------" << endl;
    Student<float> s2(45.32f, "Student 2", 21, 'M');
    s2.Display();
    cout << "--------------Student 3 --------------" << endl;
    Student<int> s3(423, "Student 3", 23, 'M');
    s3.Display();
    cout << "--------------Student 4 --------------" << endl;
    Student<double> s4(787.2, "Student 4", 25, 'M');
    s4.Display();

    return 0;
}