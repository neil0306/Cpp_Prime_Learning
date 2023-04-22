#include <iostream>

int main(void)
{
    using namespace std;

    int carrots;        // 显示地声明变量, 没有声明这个变量的话, 下面的赋值语句会报错.  ==> 代码规范是写在程序开头, 但不强制要求
                        // 需要声明变量的优势是可以防止变量名字打错, 导致系统重新创建一个变量(python里就会出这种问题)

    carrots = 25;       // 变量赋值/初始化, 变量值在存储的时候是二进制存储的, 但是在输出的时候是十进制输出的.

    cout << "I have ";  
    cout << carrots;    // 输出变量
    cout << " carrots." << endl;

    carrots = carrots -1;
    cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;    // 注意看拼接字符串的输出写法

    return 0;

}