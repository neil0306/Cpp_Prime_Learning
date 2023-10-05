#include <iostream>
#include "mytimer2.h"
using namespace std;

int main(void)
{
    Time coding(4, 35);
    Time fixing(2, 47);
    Time total;

    cout << "coding time:\n";
    coding.show();

    cout << "fixing time:\n";
    fixing.show();

    total = coding + fixing;        // 使用运算符重载
    cout << "Total time:\n";
    total.show();

    Time diff = coding - fixing;
    diff.show();

    Time adjusted = coding * 1.5;
    adjusted.show();

    return 0;
}
