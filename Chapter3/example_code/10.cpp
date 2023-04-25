#include <iostream>

int main(void)
{
    using namespace std;

    float hats, heads;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Enter a number: ";
    cin >> hats;                        // 输入 50.25
    cout << "Enter another number: ";
    cin >> heads;                       // 输入 11.17

    cout << "hats = " << hats << ", heads = " << heads << endl;

    // 注: 如果不适用setf固定显示精度的话, cout 能输出一个四舍五入的结果, 比较接近手算的结果
    cout << "hats + heads = " << hats + heads << endl;  // 得到 61.4199981689453125, 手算是61.42, 但是二进制没办法精确表示(内存限制, float小数只能表示23位二进制数), 发生精度丢失
    // 减法
    cout << "hats - heads = " << hats - heads << endl;  // 得到 39.0800018310546875, 手算是39.08, 但是二进制没办法精确表示(内存限制, float小数只能表示23位二进制数), 发生精度丢失
    // 乘法
    cout << "hats * heads = " << hats * heads << endl;  // 得到 560.29248046875, 手算是560.2925, 但是二进制没办法精确表示(内存限制, float小数只能表示23位二进制数), 发生精度丢失
    // 除法
    cout << "hats / heads = " << hats / heads << endl;  // 得到 4.501345157623291, 手算是4.501345, 但是二进制没办法精确表示(内存限制, float小数只能表示23位二进制数), 发生精度丢失

    return 0;
}