#include <iostream>
#include <cmath>

int main(void)
{
    using namespace std;

    double area;

    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;

    double side;
    side = sqrt(area);
    cout << "That's the equavalent of a square " << side
         << " feet to the side." 
         << endl;

    return 0;
}