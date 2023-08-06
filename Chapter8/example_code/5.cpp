#include <iostream>

using namespace std;
double cube(double x);
double recube(double &ra);

int main(void)
{
    double x = 3.0;
    cout << "Cube of X: " << cube(x) << endl;

    cout << "Recube of X: " << recube(x) << endl;
    cout << "X = " << x << endl;

    return 0;
}

double cube(double x)
{
    x *= x * x;
    return x;
}

double recube(double &ra)
{
    ra *= ra * ra;
    return ra;
}