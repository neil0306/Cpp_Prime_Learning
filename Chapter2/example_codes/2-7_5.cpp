#include <iostream>
using namespace std;

int main(void)
{
    cout << "Please input a number of degree celcius: ";
    int d_celcius;
    cin >> d_celcius;
    cout << d_celcius
         << " degrees celcius is "
         << d_celcius * 1.8 + 32.0
         << " degrees fahrenheit."
         << endl;

    return 0;
}