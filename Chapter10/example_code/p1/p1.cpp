#include "p1.h"

BankAccount::BankAccount(string client, string num, double bal)
{
    name = client;
    accountNumber = num;
    balance = bal;
}

void BankAccount::show(void) const       // 显示
{
    cout << "The Account Information: " << endl;
    cout << "Name: " << name << endl;
    cout << "Account: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}

void BankAccount::deposit(double cash)
{
    balance += cash;
}

void BankAccount::withdraw(double cash)
{
    balance -= cash;
}
