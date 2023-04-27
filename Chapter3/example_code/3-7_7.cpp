#include <iostream>

const double GALLON_TO_LITER = 3.875;
const double HKM_TO_MILE = 62.14;

int main(void)
{
    using namespace std;
    double fuel_comsump;


    cout << "Enter the oil comsumption of your car (l/100km): ";
    cin >> fuel_comsump;

    //换算公式 
    cout << "Your car comsumes " << (GALLON_TO_LITER * HKM_TO_MILE) / fuel_comsump << " miles per gallon." << endl;

    return 0;
}








