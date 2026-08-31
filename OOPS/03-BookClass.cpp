#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    float price;
    string isbn;

public:

    void READ()
    {
        cout << "Enter Title: ";
        getline(cin >> ws, title);

        cout << "Enter Author: ";
        getline(cin >> ws, author);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter ISBN No.: ";
        cin >> isbn;
    }

    void Display()
    {
        cout << left
             << setw(25) << title
             << setw(20) << author
             << setw(12) << price
             << setw(20) << isbn
             << endl;
    }

    bool SearchBook(string searchISBN)
    {
        return isbn == searchISBN;
    }
};

int main()
{
    Book books[5];
    string searchISBN;
    bool found = false;

    cout << "========== ENTER BOOK DETAILS ==========\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\nBook " << i + 1 << ":\n";
        books[i].READ();
    }

    // Display all books
    cout << "\n\n========== BOOK DETAILS ==========\n";

    cout << left
         << setw(25) << "Title"
         << setw(20) << "Author"
         << setw(12) << "Price"
         << setw(20) << "ISBN No."
         << endl;

    cout << "---------------------------------------------------------------------\n";

    for (int i = 0; i < 5; i++)
    {
        books[i].Display();
    }

    // Search book
    cout << "\nEnter ISBN No. to search: ";
    cin >> searchISBN;

    for (int i = 0; i < 5; i++)
    {
        if (books[i].SearchBook(searchISBN))
        {
            cout << "\n========== BOOK FOUND ==========\n";

            cout << left
                 << setw(25) << "Title"
                 << setw(20) << "Author"
                 << setw(12) << "Price"
                 << setw(20) << "ISBN No."
                 << endl;

            cout << "---------------------------------------------------------------------\n";

            books[i].Display();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook with ISBN " << searchISBN
             << " not found.\n";
    }

    return 0;
}