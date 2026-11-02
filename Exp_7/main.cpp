
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BankException : public exception
{
protected:
    string message;

public:
    BankException(string msg)
    {
        message = msg;
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance for withdrawal.")
    {
    }
};

class InvalidAmountException : public BankException
{
public:
    InvalidAmountException()
        : BankException("Error: Amount must be greater than zero.")
    {
    }
};

class BankAccount
{
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
    }

    void display()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account("Arun", 5000);

    cout << "Initial Account Details:" << endl;
    account.display();

    try
    {
        cout << "\nDepositing Rs. 1000..." << endl;
        account.deposit(1000);

        cout << "Withdrawing Rs. 2000..." << endl;
        account.withdraw(2000);

        cout << "Withdrawing Rs. 10000..." << endl;
        account.withdraw(10000);
    }
    catch (const InsufficientFundsException &e)
    {
        cout << e.what() << endl;
    }
    catch (const InvalidAmountException &e)
    {
        cout << e.what() << endl;
    }
    catch (const BankException &e)
    {
        cout << "Bank Exception: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "General Exception: " << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.display();

    cout << "\n----- Test Case 1: Invalid Deposit -----" << endl;

    BankAccount account2("Priya", 3000);
    account2.display();

    try
    {
        account2.deposit(-500);
    }
    catch (const InvalidAmountException &e)
    {
        cout << e.what() << endl;
    }

    cout << "Final Account Details:" << endl;
    account2.display();

    cout << "\n----- Test Case 2: Successful Withdrawal -----" << endl;

    BankAccount account3("Kumar", 8000);
    account3.display();

    try
    {
        account3.withdraw(3000);
        cout << "Withdrawal successful." << endl;
    }
    catch (const BankException &e)
    {
        cout << e.what() << endl;
    }

    cout << "Final Account Details:" << endl;
    account3.display();

    return 0;
}
