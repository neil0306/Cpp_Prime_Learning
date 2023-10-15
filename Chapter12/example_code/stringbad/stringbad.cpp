#include "stringbad.h"
#include <cstring>      // 调用统计字符串长度的函数strlen

/* 首先处理一下静态变量 num_string:
    1. 这个变量的初始化 **不可以** 放在"构造函数"或"类的声明的任意位置", 因为这个变量不专属于任意一个对象, 它是共享的
    2. 静态变量是独立于对象存储的, 它于类的对象在内存中的存放区域不一样.
    3. 这种变量的初始化一般不要放在头文件中, 因为头文件可能会被个位置include, 导致初始化语句有多条, 一般只放在 定义类方法的cpp 文件中
    4. 初始化该变量时, 不需要再写 static, 需要使用作用域运算符::来指定它所属的类
*/
int StringBad::num_strings = 0;     

StringBad::StringBad(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];        // new 了一块内存用于存放传入的字符串, 不然跑完这个函数之后, s里的东西就会被系统删掉
    strcpy(str, s);                 // 把s的内存拷贝到开辟的内存空间中
    num_strings++;
    cout << num_strings << ": \"" << str << ".\"" << endl;
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << ".\"" << endl;
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" Object Deleted." << endl;
    num_strings--;
    cout << num_strings << " objects left" << endl;
    delete[] str;       // 别漏了 [], 因为是字符数组!
} 

ostream & operator<<(ostream &os, const StringBad &st)
{
    os << st.str;
    return os;
}