#include <iostream>
#include "stock00.h"
using namespace std;

int main(void)
{
    Stock fluffy_the_cat;  // 实例化了一个对象
    fluffy_the_cat.acquire("NanoSmart", 20, 12.5);      // 买入一支股票
    fluffy_the_cat.show();                              // 显示结果

    cout << "-------" << endl;
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();

    cout << "-------" << endl;
    fluffy_the_cat.sell(400, 20);
    fluffy_the_cat.show();

    cout << "-------" << endl;
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();

    cout << "-------" << endl;
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();

    return 0;
}
