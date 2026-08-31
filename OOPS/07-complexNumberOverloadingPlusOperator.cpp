#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    void getData()
    {
        cout << "Enter real part: ";
        cin >> real;

        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display()
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    // Integer + Complex
    Complex operator+(int a)
    {
        Complex temp;
        temp.real = real + a;
        temp.imag = imag;
        return temp;
    }

    // Complex + Complex
    Complex operator+(Complex S2)
    {
        Complex temp;
        temp.real = real + S2.real;
        temp.imag = imag + S2.imag;
        return temp;
    }
};

int main()
{
    Complex S1, S2, S3;
    int a;

    cout << "Enter first complex number:" << endl;
    S1.getData();

    cout << "\nEnter second complex number:" << endl;
    S2.getData();

    cout << "\nEnter an integer: ";
    cin >> a;

    // S1 + S2
    S3 = S1 + S2;

    cout << "\nS1 + S2 = ";
    S3.display();

    // S2 + a
    S3 = S2 + a;

    cout << "S2 + a = ";
    S3.display();

    return 0;
}