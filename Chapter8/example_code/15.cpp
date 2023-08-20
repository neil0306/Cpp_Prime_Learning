#include <iostream>

using namespace std;

// 模板函数
template <class T>
T lesser(T a, T b) 
{
    return a < b ? a : b;
}

// 非模板函数: 返回绝对值的最小者
int lesser(int a, int b)
{
    a = a < 0 ? -a: a;
    b = b < 0 ? -b: b;
    return a < b ? a : b;
}

int main(void)
{
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    // 让编译器去选择调用的函数
    cout << lesser(m, n) << endl;   // 优先调用非模板函数(返回绝对值最小者)
    cout << lesser(x, y) << endl;   // 非模板函数不是完全匹配, 此时调用模板函数

    // 用户指定调用哪个函数, 不让编译器自己去选
    cout << "\n用户使用 <> 来指定调用模板函数:" << endl;
    cout << lesser<>(m, n) << endl;     // <> 什么都不写, 表示指定选择模板函数, 并且自动选择正确的参数类型
    cout << lesser<int>(x, y) << endl;  // <int> 表示 将实参进行一次强制类型转换, 然后调用模板函数

    return 0;
}
