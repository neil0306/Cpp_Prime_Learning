#include <iostream>

int main(void)
{
    using namespace std;

    double mile, fuel;
    cout << "Enter the distance in mile: ";
    cin >> mile; 
    cout << "Enter the fuel consumption in gallon: ";
    cin >> fuel;
    cout << "The fuel consumption is " << mile / fuel << " gallon per mile." << endl;

    double liter, kilometer;
    cout << "Enter the distance in kilometer: ";
    cin >> kilometer;
    cout << "Enter the fuel consumption in liter: ";
    cin >> liter;
    cout << "The fuel consumption is " << liter / kilometer * 100 << " liter per 100 kilometer." << endl;
    
    return 0;
}