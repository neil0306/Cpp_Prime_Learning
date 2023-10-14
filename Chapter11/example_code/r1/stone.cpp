#include <iostream>
#include "stonewt.h"

using namespace std;

int main(void)
{
    Stonewt taft(10, 8);       // 调用 Stonewt(double) 构造函数

    taft = taft * 2.0;
    taft.show_lbs();
    taft.show_stone();
    return 0;
}
