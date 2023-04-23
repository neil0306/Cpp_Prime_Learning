#include <iostream>
using namespace std;

double convert_distance(double light_years);

int main(void)
{
    double light_years;
    cout << "Enter the number of light years: ";
    cin >> light_years;

    double distance = convert_distance(light_years);


    cout << light_years
         << " light years = "
         << distance
         << " astronomical units."
         << endl;
    return 0;
}

double convert_distance(double light_years)
{
    return light_years * 63240;
}