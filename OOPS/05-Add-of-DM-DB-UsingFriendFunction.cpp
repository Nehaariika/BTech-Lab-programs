#include <iostream>
using namespace std;

class DB;   // Forward declaration

class DM
{
private:
    int meter;
    float centimeter;

public:

    void read()
    {
        cout << "Enter distance in meters: ";
        cin >> meter;

        cout << "Enter distance in centimeters: ";
        cin >> centimeter;
    }

    void display()
    {
        cout << meter << " M " << centimeter << " CM";
    }

    friend DM add(DM, DB);
};


class DB
{
private:
    int feet;
    float inches;

public:

    void read()
    {
        cout << "Enter distance in feet: ";
        cin >> feet;

        cout << "Enter distance in inches: ";
        cin >> inches;
    }

    void display()
    {
        cout << feet << " FT " << inches << " Inches";
    }

    friend DM add(DM, DB);
};


// Friend function
DM add(DM d1, DB d2)
{
    DM result;

    // Convert DB (feet and inches) into centimeters
    float totalInches = (d2.feet * 12) + d2.inches;
    float dbInCm = totalInches * 2.54;

    // Convert DM into total centimeters
    float dmInCm = (d1.meter * 100) + d1.centimeter;

    // Add both distances
    float totalCm = dmInCm + dbInCm;

    // Convert result back to meters and centimeters
    result.meter = totalCm / 100;
    result.centimeter = totalCm - (result.meter * 100);

    return result;
}


int main()
{
    DM d1;
    DB d2;
    DM result;

    cout << "========== ENTER DM DISTANCE ==========\n";
    d1.read();

    cout << "\n========== ENTER DB DISTANCE ==========\n";
    d2.read();

    result = add(d1, d2);

    cout << "\n========== RESULT ==========\n";
    cout << "DM Distance: ";
    d1.display();

    cout << "\nDB Distance: ";
    d2.display();

    cout << "\n\nSum: ";
    result.display();

    return 0;
}