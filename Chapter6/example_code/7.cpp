// 这个代码是用来测试 非运算符的
#include <iostream>
#include <climits>    // c 中的 limit.h 头文件, 里面有各种数据类型的取值范围

using namespace std;

bool is_int(double x);  // 自定义了一个函数, 记得声明!

int main(void)
{
    double number;    // 由于 cin 会自动把超出 int 范围的数值截断, 所以我们先用double类型存储输入值

    cout << "Enter an integer number: ";
    cin >> number;

    while (! is_int(number))
    {
        cout << "Out of range, please enter again: ";
        cin >> number;
    }
    int value = (int) number;   // 为了保证是 int 输出, 这里进行强制类型转换
    cout << "You've enter the integer: " << value << endl; 

    return 0;
}

bool is_int(double x)
{
    if (x <= INT_MAX && x >= INT_MIN)
        return true;
    else 
        return false;

}