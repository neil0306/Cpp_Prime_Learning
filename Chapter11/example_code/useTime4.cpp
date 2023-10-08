#include <iostream>
#include "mytimer4.h"
using namespace std;

int main(void)
{
    Time coding(4, 35);
    Time fixing(2, 47);
    Time total;

    cout << "coding time:\n";
    // coding.show();
    cout << coding;

    cout << "fixing time:\n";
    // fixing.show();
    cout << fixing;

    total = coding + fixing;        // 使用运算符重载
    cout << "Total time:\n";
    // total.show();
    cout << total;

    Time diff = coding - fixing;
    // diff.show();
    cout << diff;

    Time adjusted = coding * 1.5;       // 成员函数的运算符重载
    // adjusted.show();
    cout << adjusted;

    adjusted = 1.5 * coding;            // 非成员函数的运算符重载
    // adjusted.show();
    cout << adjusted;

    cout << "******************" << endl;
    cout << coding << fixing;       // 连续输出, 使用友元函数
    return 0;
}
