#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Base class
class Student
{
protected:
    string USN;
    string Name;
    int Age;

public:
    void readStudent()
    {
        cout << "Enter USN: ";
        cin >> USN;

        cout << "Enter Name: ";
        getline(cin >> ws, Name);

        cout << "Enter Age: ";
        cin >> Age;
    }
};

// Derived class for UG students
class UG : public Student
{
private:
    int Semester;
    float Fees;
    float Stipend;

public:
    void read()
    {
        readStudent();

        cout << "Enter Semester: ";
        cin >> Semester;

        cout << "Enter Fees: ";
        cin >> Fees;

        cout << "Enter Stipend: ";
        cin >> Stipend;
    }

    int getSemester()
    {
        return Semester;
    }

    int getAge()
    {
        return Age;
    }

    void display()
    {
        cout << left << setw(15) << USN
             << setw(20) << Name
             << setw(8) << Age
             << setw(12) << Semester
             << setw(12) << Fees
             << setw(12) << Stipend << endl;
    }
};

// Derived class for PG students
class PG : public Student
{
private:
    int Semester;
    float Fees;
    float Stipend;

public:
    void read()
    {
        readStudent();

        cout << "Enter Semester: ";
        cin >> Semester;

        cout << "Enter Fees: ";
        cin >> Fees;

        cout << "Enter Stipend: ";
        cin >> Stipend;
    }

    int getSemester()
    {
        return Semester;
    }

    int getAge()
    {
        return Age;
    }

    void display()
    {
        cout << left << setw(15) << USN
             << setw(20) << Name
             << setw(8) << Age
             << setw(12) << Semester
             << setw(12) << Fees
             << setw(12) << Stipend << endl;
    }
};

int main()
{
    UG ug[5];
    PG pg[5];

    int nUG, nPG;

    cout << "Enter number of UG students (minimum 5): ";
    cin >> nUG;

    cout << "\n========== ENTER UG STUDENT DETAILS ==========\n";

    for (int i = 0; i < nUG; i++)
    {
        cout << "\nUG Student " << i + 1 << ":\n";
        ug[i].read();
    }

    cout << "\nEnter number of PG students (minimum 5): ";
    cin >> nPG;

    cout << "\n========== ENTER PG STUDENT DETAILS ==========\n";

    for (int i = 0; i < nPG; i++)
    {
        cout << "\nPG Student " << i + 1 << ":\n";
        pg[i].read();
    }

    // Display UG students
    cout << "\n\n========== UG STUDENTS ==========\n";

    cout << left << setw(15) << "USN"
         << setw(20) << "Name"
         << setw(8) << "Age"
         << setw(12) << "Semester"
         << setw(12) << "Fees"
         << setw(12) << "Stipend" << endl;

    cout << "---------------------------------------------------------------------\n";

    for (int i = 0; i < nUG; i++)
    {
        ug[i].display();
    }

    // Display PG students
    cout << "\n\n========== PG STUDENTS ==========\n";

    cout << left << setw(15) << "USN"
         << setw(20) << "Name"
         << setw(8) << "Age"
         << setw(12) << "Semester"
         << setw(12) << "Fees"
         << setw(12) << "Stipend" << endl;

    cout << "---------------------------------------------------------------------\n";

    for (int i = 0; i < nPG; i++)
    {
        pg[i].display();
    }

    // Semester-wise average age for UG
    cout << "\n\n UG SEMESTER-WISE AVERAGE AGE \n";
    cout << left << setw(15) << "Semester"
         << setw(15) << "Average Age" << endl;

    cout << "------------------------------\n";

    for (int sem = 1; sem <= 8; sem++)
    {
        int sum = 0;
        int count = 0;

        for (int i = 0; i < nUG; i++)
        {
            if (ug[i].getSemester() == sem)
            {
                sum += ug[i].getAge();
                count++;
            }
        }

        if (count > 0)
        {
            cout << left << setw(15) << sem
                 << setw(15) << fixed << setprecision(2)
                 << (float)sum / count << endl;
        }
    }

    // Semester-wise average age for PG
    cout << "\n\n PG SEMESTER-WISE AVERAGE AGE \n";
    cout << left << setw(15) << "Semester"
         << setw(15) << "Average Age" << endl;

    cout << "------------------------------\n";

    for (int sem = 1; sem <= 8; sem++)
    {
        int sum = 0;
        int count = 0;

        for (int i = 0; i < nPG; i++)
        {
            if (pg[i].getSemester() == sem)
            {
                sum += pg[i].getAge();
                count++;
            }
        }

        if (count > 0)
        {
            cout << left << setw(15) << sem
                 << setw(15) << fixed << setprecision(2)
                 << (float)sum / count << endl;
        }
    }

    return 0;
}