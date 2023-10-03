#include <iostream>
#include "p1.h"

int main(void)
{
    BankAccount n1("Rick", "0001", 1000);
    n1.show();
    cout << "-------" << endl;

    n1.deposit(500);
    cout << "After deposit: "<< endl;
    n1.show();
    cout << "-------" << endl;

    n1.withdraw(800);
    cout << "After widthdraw: "<< endl;
    n1.show();

    return 0;
}
