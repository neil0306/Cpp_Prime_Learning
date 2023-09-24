#include <iostream>
#include "stock10.h"
using namespace std;

int main(void)
{
    // method 1: 隐式调用构造函数
    Stock stock1("NanoSmart", 12, 20.0);
    stock1.show();

    cout << "------" << endl;

    // method 2: 显式地使用构造函数
    Stock stock2 = Stock("Boffo Object", 250, 1.25);
    stock2.show();

    // 测试默认构造函数(两种默认构造函数都用这个方式测)
    cout << "\nTesting default construction...." << endl;
    Stock stock3;
    stock3.show();

    return 0;
}
