/*
    如果开发者是自己一个人, 那么老师在定义函数时的习惯是:
        1. 先写函数的调用 (在main函数中一直写, 写到突然需要定义一个函数方便复用一段代码时, 就先把这段代码写到函数中, 并在这个位置写上函数的调用)
        2. 再写函数的定义 (在main函数的后面写, 一般是在main函数的后面)
        3. 在mian函数前面(或者写进一个头文件中)补上函数的声明/原型
*/
#include <iostream>

using namespace std;

void simple(void);      // 函数的原型, 函数的声明  (declare), 别忘记加分号

int main(void)
{
    cout << "main() will call the simple() function." << endl;

    simple();

    return 0;
}

void simple(void)
{
    cout << "I'm just a simple functino." << endl;
}
