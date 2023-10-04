#include <iostream>
#include "p7.h"

using namespace std;

int main(void)
{
    plorg p1;       // 默认构造
    p1.show();

    p1.reset(100);
    p1.show();

    return 0;
}