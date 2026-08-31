#include <iostream>
using namespace std;

class Number
{
    int n;

public:
    void getData()
    {
        cout << "Enter a number: ";
        cin >> n;
    }

    void display()
    {
        cout << "Number = " << n << endl;
    }

    void operator-()
    {
        n = -n;
    }
};

int main()
{
    Number obj;

    obj.getData();

    cout << "Before changing sign:" << endl;
    obj.display();

    -obj;   // Unary - operator overloaded

    cout << "After changing sign:" << endl;
    obj.display();

    return 0;
}