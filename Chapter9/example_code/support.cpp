#include <iostream>
#include "support.h"

using namespace std;

/// @brief 修改全局变量, dt是增加值
/// @param dt 
void update(double dt)
{
    warming  += dt;
    cout << "Updating Global Warming to " << warming << " degrees." << endl;
}

void local(void)
{
    // 局部变量, 只在local函数内部可见
    double warming = 0.8;
    cout << "Local Warming = " << warming << " degrees." << endl;

    // 使用作用域解析运算符 "::" (两个冒号), 表明这个变量是全局变量
    cout << "But global warming = " << ::warming << " degrees." << endl;
}