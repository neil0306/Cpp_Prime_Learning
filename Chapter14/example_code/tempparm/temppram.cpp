#include <iostream>
#include "stack.h"

using namespace std;

template <template <class T> class Thing>      // Thing 是一个 "模板类" 类型
class Crab
{
    private:
        Thing<int> s1;       // 创建一个 Thing<int> 类型的对象 s1
        Thing<double> s2;
    public:
        bool push(int a, double x){return (s1.push(a) && s2.push(x));}  // 两个元素分别入栈成功时, 函数才返回 true
        bool pop(int &a, double &x){return (s1.pop(a) && s2.pop(x));}   // 两个元素分别出栈成功时, 函数才返回 true
};

int main(void)
{
    int ni;     // 输入的int数据
    double nb;  // 输入的double数据
    Crab<Stack> nebula;     // Stack 是一个模板类, 此时没有显示地执行实例化
    /*
    分析:
        1. nebula 是 Crab<Stack> 类型
        2. nebula 有两个私有成员 s1 和 s2, 它们分别是 Stack<int> 和 Stack<double> 类型
    */

    // 测试入栈
    cout << "Enter int & double pairs, such as 2 3.4 (0 0 to end): " << endl;
    while ((cin >> ni >> nb) && (ni > 0 && nb > 0))
    {
        // 调用nebula的成员函数入栈
        if (!nebula.push(ni, nb))        // 入栈失败时跳出循环
            break;
    }

    // 测试出栈
    while (nebula.pop(ni, nb)){
        cout << ni << ", " << nb << endl;
    }

    return 0;
}