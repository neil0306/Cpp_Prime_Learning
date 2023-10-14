#include <iostream>
#include "stonewt1.h"

using namespace std;

int main(void)
{
    Stonewt poppings(9, 2.8);
    double p_wt = poppings;     // 触发隐式调用: 左侧是double类型, 右侧是类的对象, 编译器自动寻找转换函数
    cout << "poppings = " << p_wt << " pounds." << endl;

    int weight = poppings;      // 触发隐式调用
    cout << "poppings = " << weight << " pounds." << endl;

    cout << "poppings = " << int(poppings) << " pounds." << endl;       // 显式转换
    cout << "poppings = " << double(poppings) << " pounds." << endl;

    /*
        cout << "poppings = " << poppings << " pounds." << endl;     
            这种写法会触发"二义性问题":
                1. 因为成员函数中存在两个转换函数, 而我们没有指定使用哪个类型的转换函数
                2. 如果成员函数中只定义了一种转换函数, 此时就没有二义性问题了
    */
    return 0;
}
