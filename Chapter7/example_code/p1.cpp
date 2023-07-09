#include <iostream>

using namespace std;
double harmonicMean(double x, double y);

int main(void)
{
    double n1, n2, result;
    cout << "Please enter two numbers, until one of them is zero: ";
    cin >> n1 >> n2;

    while ((0 != n1) && (0 != n2)){
        result = harmonicMean(n1, n2);
        cout << "The harmonic means is: " << result << endl;

        cout << "Please enter two numbers, until one of them is zero: ";
        cin >> n1 >> n2;
    }
    return 0;
}

double harmonicMean(double x, double y)
{
    return 2.0 * x * y / (x+y);
}

