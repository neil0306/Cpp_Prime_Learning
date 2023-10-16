#ifndef __STRINGBAD_H__
#define __STRINGBAD_H__

#include <iostream>
using namespace std;

class StringBad
{
    private:
        char *str;              // 存放的不是字符串, 而是字符串所在的地址!
        int len;

        static int num_strings; // 静态变量, 它不专属于任意一个对象, 而是所有对象共享的
                                /* 它只会被初始化一次(需要额外写一个初始化), 所有定义的对象都共享这个成员变量, 这种变量常用于统计这个类一共有多少个对象 */

    public:
        StringBad(const char *s);
        StringBad();
        StringBad(const StringBad &st);       // 复制构造函数
        ~StringBad();           // 一般在动态分配内存的场景下, 会把delete语句写在这里

        // 重载赋值运算符, 由于赋值运算符本身要求左侧是类的对象, 所以可以不定义成友元函数
        StringBad & operator=(const StringBad &st);

        friend ostream & operator<<(ostream &os, const StringBad &st);
};

#endif //!__STRINGBAD_H__