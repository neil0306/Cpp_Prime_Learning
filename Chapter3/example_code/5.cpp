#include <iostream>
using namespace std;

int main(void)
{
    char ch = 'M';   //注意, 字符型变量一定要用单引号, 双引号表示字符串, 不能赋值给char类型
    int i = ch;      //char类型赋值给int类型, 把char类型存放在内存中的值取出来了
    
    // 从下面的语句可以看到, ch 是char类型, cout 自动把它转成了对应的ASCII码, i 是整型, 啥都不干, 直接当做十进制数输出.
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code." << endl;
    ch = ch + 1;
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // 使用cout.put()函数输出字符
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);           // 点 . 运算符是"成员运算符", 用来调用对象的方法.
    cout.put('!');
    cout << endl << "Done" << endl;

    return 0;
}