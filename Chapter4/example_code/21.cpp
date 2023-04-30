#include <iostream>

int main(void)
{
    using namespace std;
    short tell[10];
    cout << tell << endl;   // 输出的是数组中, 第一个元素的地址
    cout << &tell << endl;  // 整个数组的首地址

    cout << " tell+1 : " << tell +1 << endl;   // 增加一个short类型的长度, 也就是2个字节
    cout << " &tell+1 : " << &tell +1 << endl; // 增加一个short类型数组的长度, 也就是20个字节
    return 0;
}