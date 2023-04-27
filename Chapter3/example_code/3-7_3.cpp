#include <iostream>

int main(void)
{
    using namespace std;

    double degree, minute, second;
    const double to_degree = 60, to_minute = 60;

    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;

    cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = " << degree + minute / to_degree + second / (to_minute * to_degree) << " degrees" << endl;

    return 0;
}