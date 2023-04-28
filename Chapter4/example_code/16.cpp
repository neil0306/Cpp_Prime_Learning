#include <iostream>

int main(void)
{
    using namespace std;

    int donuts = 6;
    double cups = 4.5;

    // 内存地址的单位是 1 字节, 地址每增加1, 指向的内存单元就增加1字节
    cout << "donuts value = " << donuts << " and its address = " << &donuts << endl;    // & 取地址
    cout << "Cups value = " << cups << " and its address = " << &cups << endl;          // & 取地址
    /*
    上面语句的一个输出结果:
        donuts value = 6 and its address = 0x16dbbaec8
        Cups value = 4.5 and its address = 0x16dbbaec0
    两个地址之间相差了8, 说明两个变量之间相差了8个字节, 说明在当前的机器上, int 类型占用了8个字节 (int至少占用4个, 8个也是可以的), double 类型占用了8个字节
    */

    return 0;
}