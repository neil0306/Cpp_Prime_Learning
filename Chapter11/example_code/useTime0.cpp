#include <iostream>
#include "mytimer0.h"
using namespace std;

int main(void)
{
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "coding time:\n";
    coding.show();

    cout << "fixing time:\n";
    fixing.show();

    total = coding.Sum(fixing);
    cout << "Total time:\n";
    total.show();

    return 0;
}