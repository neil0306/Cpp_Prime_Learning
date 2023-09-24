#include <iostream>
#include "stock10.h"

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

    cout << "Assigning stock1 to stock2: \n";
    stock2 = stock1;        // 类的对象之间可以直接对拷!!!!
    cout << "Listing stock1 and stock2: \n";
    stock1.show();

    cout << "------" << endl;

    cout << "Using a constructor to reset an object: \n";
    stock1 = Stock("Nifty Foods", 10,  50.0);       // 这是一个赋值操作. 这里相当于临时创建了一个对象, 然后对拷, 从输出中可以观察到这里调用了一次析构函数
    cout << "Revised Stock1:\n";
    stock1.show();
    cout << "Done!" << endl;

    cout << "\nTesting const function...";
    const Stock land = Stock("gda", 123, 123.0);
    land.show();

    cout << "------" << endl;

    return 0;
}
