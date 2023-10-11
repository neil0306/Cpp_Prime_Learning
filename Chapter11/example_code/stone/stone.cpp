#include <iostream>
#include "stonewt.h"

using namespace std;

int main(void)
{
    // 下面这行代码将触发 "类的自动类型转换"
    Stonewt incognito = 275;    // 触发构造函数来初始化对象(先用构造函数创建一个临时对象, 然后通过"隐式"的逐成员赋值的方式完成赋值.)
                                // 等价于: Stonewt incognito(275);
                                // 也等价于: Stonewt incognito = Stonewt(275);

    Stonewt wolfe(285.7);       // 调用 Stonewt(double) 构造函数
    Stonewt taft(21, 8);

    incognito.show_stone();
    wolfe.show_stone();
    taft.show_lbs();

    cout << "----------------------------" << endl;
    incognito = 276.8;      // 再次触发自动类型转换
    taft = 325;
    wolfe = 111;
    incognito.show_stone();
    wolfe.show_stone();
    taft.show_lbs();

    return 0;
}
