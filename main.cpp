#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
int rollNo;
string name;
public:
// Constructor

Student(int r, string n)
{
rollNo = r;
name = n;
cout << "Student object created" << endl;
}
// Member function
void display()
{
cout << "Roll Number: " << rollNo << endl;
cout << "Name: " << name << endl;
}
// Destructor
~Student()
{
cout << "Student object destroyed" << endl;
}
};
int main()
{
Student s1(101, "Arun");
Student s2(102,"Meera");
Student s3(103,"Ashok");
s1.display();
s2.display();
s3.display();
return 0;
}
