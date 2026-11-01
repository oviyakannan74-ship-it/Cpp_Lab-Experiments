
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;
};

void gradeAnalyzer(vector<Student> students, int testCase)
{
    // Sort students based on marks
    sort(students.begin(), students.end(),
    [](Student a, Student b)
    {
        return a.mark > b.mark;
    });

    // Assign grades
    transform(students.begin(), students.end(),
    students.begin(),
    [](Student s)
    {
        if (s.mark >= 90)
            s.grade = 'A';
        else if (s.mark >= 75)
            s.grade = 'B';
        else if (s.mark >= 50)
            s.grade = 'C';
        else
            s.grade = 'F';

        return s;
    });

    // Find first student scoring above 80
    auto it = find_if(students.begin(), students.end(),
    [](Student s)
    {
        return s.mark > 80;
    });

    // Calculate total marks
    int total = accumulate(students.begin(), students.end(), 0,
    [](int sum, Student s)
    {
        return sum + s.mark;
    });

    float average = (float)total / students.size();

    // Display results
    cout << "\nTEST CASE " << testCase << endl;
    cout << "---------------------\n";
    cout << "Name\tMark\tGrade\n";

    for (Student s : students)
    {
        cout << s.name << "\t"
             << s.mark << "\t"
             << s.grade << endl;
    }

    if (it != students.end())
    {
        cout << "First student scoring above 80: "
             << it->name << endl;
    }
    else
    {
        cout << "No student scored above 80\n";
    }

    cout << "Total Marks: " << total << endl;
    cout << "Average Mark: " << average << endl;
}

int main()
{
    // Original Test Case
    vector<Student> test1 = {
        {"Arun", 85, ' '},
        {"Bala", 72, ' '},
        {"Kumar", 91, ' '},
        {"Ravi", 65, ' '}
    };

    // Extra Test Case 2
    vector<Student> test2 = {
        {"Priya", 95, ' '},
        {"Divya", 88, ' '},
        {"Meena", 76, ' '},
        {"Anu", 54, ' '}
    };

    // Extra Test Case 3
    vector<Student> test3 = {
        {"Rahul", 45, ' '},
        {"Vijay", 67, ' '},
        {"Karthik", 82, ' '},
        {"Ajay", 93, ' '}
    };

    cout << "STUDENT GRADE ANALYZER\n";

    gradeAnalyzer(test1, 1);
    gradeAnalyzer(test2, 2);
    gradeAnalyzer(test3, 3);

    return 0;
}
