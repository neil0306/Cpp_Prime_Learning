#include <iostream>

using namespace std;

template <typename T>
void Swap(T &a, T &b);

int main(void)
{
    int i = 10;
    int j = 20;
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    Swap(i,j);              // swap 接收 int 类型
    cout << "After Swap, now i,j = " << i << ", "<< j << endl;

    double x = 24.5;
    double y = 81.7;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    Swap(x,y);              // swap 接收 double 类型
    cout << "After Swap, now x,y = " << x << ", "<< y << endl;

    return 0;
}

// 定义一个模板函数, 来完成任意类型的参数接收. (在调用时, 编译器自动生成独立的重载函数)
template <typename T>           // 注意 <typename T> 中没有逗号也没有分号
void Swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}