# include <iostream>

int main(void)
{
    using namespace std;

    double wages[3] = {10000.0, 20000.0, 30000.0};   // double 类型的数组, 此时 wages 是数组名, 也是第一个数组元素的地址
    short stacks[3] = {3, 2, 1};     // short 类型的数组, 此时 stack 是数组名, 也是第一个数组元素的地址

    // 用两种方法获取数组的地址
    double * pw = wages;        // double 类型的指针, 直接把数组的第一个元素的地址赋给这个指针, **不需要使用 & 来取地址** 
    short * ps = &stacks[0];    // short 类型的指针, 需要使用 & 来取数组第一个元素的地址

    // 利用指针加法访问数组的下一个元素
    cout << "pw = " << pw << ", *pw = " << *pw << endl;   // pw 是指针, *pw 是指针指向的值
    pw = pw + 1;    // 指针加 1, 指向数组的下一个元素, 注意看指针变量的数值增加了多少
    cout << "add 1 to the pw pointer: \n" << "pw = " << pw << ", *pw = " << *pw << endl;

    cout << "ps = " << ps << ", *ps = " << *ps << endl;   // ps 是指针, *ps 是指针指向的值
    ps = ps + 1;    // 指针加 1, 指向数组的下一个元素, 注意看指针变量的数值增加了多少
    cout << "add 1 to the ps pointer: \n" << "ps = " << ps << ", *ps = " << *(ps) << endl;   // ps + 1 是指针, *(ps + 1) 是指针指向的值

    // 两种方式访问数组中的元素
    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;       // 用下标访问数组元素
    cout << "access two elements with pointer notation\n";
    cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << endl;   // 数组名直接当成指针使用!!

    // 使用sizeof运算符来确定数组的长度(数组名不会被解释为第一个元素的地址)
    cout << "Size of wages array = " << sizeof(wages) << endl;   // sizeof(wages) 返回数组的长度, 单位是字节; 这里打印的东西表明, C++中这个数组在使用sizeof的时候没有作为指针变量处理
            // 输出8, double 占用8个字节, 数组一共有3个元素, 所以是24

    cout << "Size of pw pointer = " << sizeof(pw) << endl;       // sizeof(pw) 返回指针变量的长度, 单位是字节
            // 输出8, double * 类型的指针变量占用8个字节
    return 0;
}