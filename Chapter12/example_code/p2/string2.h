#ifndef __STRING2_H__
#define __STRING2_H__

#include <iostream>
using namespace std;

class String
{
    private:
        char *str;              // 存放的不是字符串, 而是字符串所在的地址!
        int len;

        static int num_strings; // 静态变量, 它不专属于任意一个对象, 而是所有对象共享的
                                /* 它只会被初始化一次(需要额外写一个初始化), 所有定义的对象都共享这个成员变量, 这种变量常用于统计这个类一共有多少个对象 */
        static const int CINLIMIT = 80;     // 限制输入字符的最大值

    public:
        String(const char *s);
        String();
        String(const String &st);       // 复制构造函数
        ~String();           // 一般在动态分配内存的场景下, 会把delete语句写在这里

        int length() const
        {
            return len;
        }

        // 重载赋值运算符, 由于赋值运算符本身要求左侧是类的对象, 所以可以不定义成友元函数
        String & operator=(const String &st);
        String & operator=(const char *st);       // 直接传入一个字符串

        char & operator[](int i);                       // 重载索引运算
        const char & operator[](int i) const;

        friend bool operator<(const String &str1, const String &str2);
        friend bool operator>(const String &str1, const String &str2);
        friend bool operator==(const String &str1, const String &str2);

        friend ostream & operator<<(ostream &os, const String &st);
        friend istream & operator>>(istream &is, String &st);

        static int HowMany();       // 静态函数, 不属于任何一个对象, 它用来返回对象的个数

    // 编程题2新增的成员函数(5个):
    public:
        friend String operator+(const char *s, const String &st);     // 用char *s 表示一个字符串
        String operator+(const String &st);
        void stringlow();
        void stringup();
        int has(char c) const;
};

#endif //!__STRING2_H__
