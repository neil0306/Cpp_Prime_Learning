#include <iostream>
#include "classic.h"
using namespace std;

void Bravo(const Cd & disk);

int main(void)
{
    Cd c1("Beatles", "capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

    Cd *pcd = &c1;

    cout << "Using object directly:\n";
    c1.Report();        // 基类
    c2.Report();        // 派生类

    cout << "------------" << endl;

    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();      // 基类
    pcd = &c2;
    pcd->Report();      // 派生类

    cout << "------------" << endl;

    Bravo(c2);          // 派生类

    cout << "------------" << endl;

    cout << "Testing assignment: \n";
    Classic copy;
    copy = c2;          // 验证派生类的赋值运算符
    copy.Report();

    return 0;
} 

void Bravo(const Cd &disk)
{
    disk.Report();
}