#include <iostream>
#include "mytimer1.h"
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

    // total = coding.Sum(fixing);
    total = coding + fixing;        // 使用运算符重载
    cout << "Total time:\n";
    total.show();

    // 运算符重载的使用方式也可以写为下面的语句(当做成员函数来使用)
    Time Planning = coding.operator+(fixing);
    cout << "Planning time:\n";
    Planning.show();

    return 0;
}