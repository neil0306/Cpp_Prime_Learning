#include "cow.h"
#include <iostream>
using namespace std;

int main(void)
{
    Cow cow1;           // 默认构造
    Cow cow2("cow2", "badminton", 123); // 自定义构造
    Cow cow3(cow2);     // 复制构造
    cow1 = cow2;        // 重载的赋值运算符

    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();

    return 0;
}