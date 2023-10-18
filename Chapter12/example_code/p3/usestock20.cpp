#include <iostream>
#include "stock20.h"

int main(void)
{
    using namespace std;
    // method 1: 隐式调用构造函数
    Stock stock1("NanoSmart", 12, 20.0);
    cout << stock1;
    cout << "------" << endl;

    // method 2: 显式地使用构造函数
    Stock stock2 = Stock("Boffo Object", 250, 1.25);    // 这是一个初始化操作, 效率比下面的stock1赋值操作高, 因为这里没有创建临时对象!
    cout << stock2;
    cout << "------" << endl;

    // 比较两支股票
    // Stock top = stock1.topval(stock2);          // 这里会触发复制构造函数, 由于我们没有没有定义复制构造函数, 编译器提供的复制构造也不会行进new, 因此析构会出问题
    const Stock *top = &stock1.topval(stock2);     // 改成对象指针的话, 这里就不会触发复制构造了(注意没有new, 所以不会触发构造), 根据返回值类型, 我们还需要加const
    cout << "Now show the top val: " << endl;
    cout << *top;

    return 0;
}
