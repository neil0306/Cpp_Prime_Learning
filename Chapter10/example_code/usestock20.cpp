#include <iostream>
#include "stock20.h"

int main(void)
{
    using namespace std;
    // method 1: 隐式调用构造函数
    Stock stock1("NanoSmart", 12, 20.0);
    stock1.show();
    cout << "------" << endl;

    // method 2: 显式地使用构造函数
    Stock stock2 = Stock("Boffo Object", 250, 1.25);    // 这是一个初始化操作, 效率比下面的stock1赋值操作高, 因为这里没有创建临时对象!
    stock2.show();
    cout << "------" << endl;

    // 比较两支股票
    Stock top = stock1.topval(stock2);
    cout << "Now show the top val: " << endl;
    top.show();

    return 0;
}
