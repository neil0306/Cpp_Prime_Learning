#include <iostream>

int main(void)
{
    using namespace std;

    double *p3 = new double [3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << endl;  // 动态数组元素的访问

    // 动态数组的指针算术运算
    p3 = p3 + 1;  // 指针向后移动一个元素
    cout << "Now p3[0] is " << p3[0] << " and "
         << "p3[1] is " << p3[1] << endl;   // p3[0] 指向了原来的 p3[1] 的位置，p3[1] 指向了原来的 p3[2] 的位置

    p3 = p3 - 1;  // 指针向前移动一个元素

    delete [] p3; // 释放动态数组的内存
    return 0;
}