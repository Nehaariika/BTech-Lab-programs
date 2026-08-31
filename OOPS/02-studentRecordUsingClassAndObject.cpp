#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    string reg_no;
    float marks1, marks2, marks3;

public:

    void read()
    {
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Registration Number: ";
        getline(cin, reg_no);

        cout << "Enter marks in Subject 1: ";
        cin >> marks1;

        cout << "Enter marks in Subject 2: ";
        cin >> marks2;

        cout << "Enter marks in Subject 3: ";
        cin >> marks3;
    }

    float average()
    {
        return (marks1 + marks2 + marks3) / 3.0;
    }

    void display()
    {
        cout << "\n========== STUDENT RECORD ==========\n";

        cout << left
             << setw(20) << "Name"
             << setw(15) << "Reg. No."
             << setw(12) << "Subject 1"
             << setw(12) << "Subject 2"
             << setw(12) << "Subject 3"
             << setw(12) << "Average"
             << endl;

        cout << "---------------------------------------------------------------\n";

        cout << left
             << setw(20) << name
             << setw(15) << reg_no
             << setw(12) << marks1
             << setw(12) << marks2
             << setw(12) << marks3
             << fixed << setprecision(2) << average()
             << endl;
    }
};

int main()
{
    Student s;

    s.read();
    s.display();

    return 0;
}