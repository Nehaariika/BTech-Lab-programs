#include <iostream>
using namespace std;

// Base class
class Student
{
protected:
    int rollNo;
    string name;

public:
    void readStudent()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Student Name: ";
        cin >> name;
    }
};

// Intermediate class
class Exam : public Student
{
protected:
    int subject1, subject2, subject3;

public:
    void readExam()
    {
        readStudent();

        cout << "Enter marks of Subject 1: ";
        cin >> subject1;

        cout << "Enter marks of Subject 2: ";
        cin >> subject2;

        cout << "Enter marks of Subject 3: ";
        cin >> subject3;
    }
};

// Internal Exam class
class InternalExam : virtual public Exam
{
protected:
    int internalMarks;

public:
    void readInternal()
    {
        cout << "Enter Internal Exam marks: ";
        cin >> internalMarks;
    }
};

// External Exam class
class ExternalExam : virtual public Exam
{
protected:
    int externalMarks;

public:
    void readExternal()
    {
        cout << "Enter External Exam marks: ";
        cin >> externalMarks;
    }
};

// Result class
class Result : public InternalExam, public ExternalExam
{
public:
    void displayResult()
    {
        cout << "\n========== STUDENT RESULT ==========\n";

        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;

        cout << "\nInternal Marks : " << internalMarks << endl;
        cout << "External Marks : " << externalMarks << endl;

        cout << "\nTotal Marks    : "
             << internalMarks + externalMarks << endl;
    }
};

int main()
{
    Result r;

    cout << "========== ENTER STUDENT DETAILS ==========\n";

    r.readExam();

    r.readInternal();

    r.readExternal();

    r.displayResult();

    return 0;
}