#include <iostream>
#include <string>
using namespace std;

class BANK
{
private:
    string name;
    long long accountNumber;
    string accountType;
    double balance;

    static int noOfTransactions;

public:

    // Function to read account details
    void read()
    {
        cout << "Enter Account Holder Name: ";
        getline(cin >> ws, name);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Type of Account: ";
        cin >> accountType;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Function to display account details
    void display()
    {
        cout << "\n========== ACCOUNT DETAILS ==========\n";
        cout << "Account Holder Name : " << name << endl;
        cout << "Account Number      : " << accountNumber << endl;
        cout << "Account Type        : " << accountType << endl;
        cout << "Balance             : " << balance << endl;
    }

    // Function to deposit amount
    void deposit()
    {
        double amount;

        cout << "\nEnter amount to deposit: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            noOfTransactions++;

            cout << "Amount deposited successfully.\n";
            cout << "Updated Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    // Function to withdraw amount
    void withdraw()
    {
        double amount;

        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance!\n";
        }
        else
        {
            balance -= amount;
            noOfTransactions++;

            cout << "Amount withdrawn successfully.\n";
            cout << "Remaining Balance: " << balance << endl;
        }
    }

    // Static function to display number of transactions
    static void displayTransactions()
    {
        cout << "\nTotal Number of Transactions: "
             << noOfTransactions << endl;
    }
};

// Definition and initialization of static data member
int BANK::noOfTransactions = 0;


int main()
{
    BANK account;

    // Read account details
    account.read();

    // Display account details
    account.display();

    // Deposit amount
    account.deposit();

    // Withdraw amount
    account.withdraw();

    // Display updated account details
    account.display();

    // Call static member function
    BANK::displayTransactions();

    return 0;
}