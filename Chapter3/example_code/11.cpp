#include <iostream>

int main(void)
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Integer division: 9/5 = " << 9 / 5 << endl;  // 输出1, 丢弃了小数部分
    cout << "Floating-point division: 9.0/5.0 = " << 9.0/5.0 << endl;        // 输出1.800000 
    cout << "Mixed division: 9.0/5 = " << 9.0/5 << endl;    // 输出1.800000
    cout << "double constants: 1e7/9.0 = " << 1e7/9.0 << endl;     // 输出1111111.111111, 数字后啥都不加, 默认处理为 double
    cout << "float constants: 1e7f/9.0f = " << 1e7f/9.0f << endl;  // 输出1111111.125000, 数字后面加 f 或 F, 标记为 float

    return 0;
}