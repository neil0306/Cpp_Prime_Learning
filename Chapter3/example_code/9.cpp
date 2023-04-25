#include <iostream>
using namespace std;

int main(void)
{
    float a = 2.34E+22;
    float b = a + 1.0;

    cout << "a = " << a << endl;

    // 运算过程中, 精度降低的例子
    cout << "b - a = " << b - a << endl; // 正常情况下, 差值是1, 但是程序输出是0.

    return 0;
}