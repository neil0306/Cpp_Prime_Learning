#include <iostream>
using namespace std;

int main(void)
{
    cout.setf(ios_base::fixed, ios_base::floatfield); // iostream 的常量, 后面章节会讲, 这里直接用, 先不管
    
    // 测试 float 类型的精度
    float tub = 10.0/3.0;
    const float million = 1.0E6;

    cout << "tub = " << tub <<endl;                                 // 默认只输出小数点后六位
    cout << "A million tubs = " << million * tub << endl;           // 打印的数字是 3333333.250000, 小数点部分是错的 
    cout << "Ten million tubs = " << 10 * million * tub << endl;    // 数字部分是 33333332.000000, 这个除法结果是错的, 原因是float精度达不到要求

    // 测试 double 类型的精度
    double mint = 10.0/3.0;
    cout << "mint = " << mint << endl;
    cout << "A million mints = " << million * mint << endl;        // 3333333.333333, 结果正确
    cout << "Ten million mints = " << 10 * million * mint << endl; // 3333333.333333, 结果正确

    return 0;
}