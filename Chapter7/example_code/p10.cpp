#include <iostream>
using namespace std;

double add(double x, double y);
double subtract (double x, double y);
double calculate(double x, double y, double (*pt) (double x, double y));

int main(void)
{
    double result = calculate(2.5, 10.4, add);
    cout << "The result of add is: " << result << endl;

    result = calculate(10.4, 2.5, subtract);
    cout << "The result of subtract is: " << result << endl;
    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double subtract (double x, double y)
{
    return x - y;
}

double calculate(double x, double y, double (*pt) (double x, double y))
{
    return pt(x, y);
}