#include <iostream>

using namespace std;

int main(void)
{
    double income;
    double tax;

    cout << "Please enter your income: ";

    while ((cin >> income) && (income >= 0) )
    {
        if (income <= 5000)
            tax = 0.0;
        else if (income <= 15000)
            tax = 0.1 * (income - 5000);
        else if (income <= 35000)
            tax = 10000*0.1 + 0.15 * (income - 15000);
        else
            tax = 10000*0.1 + 0.15 * 20000 + (income - 35000) * 0.2;
        
        cout << "Your tax = " << tax << endl;
        cout << "Please enter your income." << endl;
    }

    return 0;
}