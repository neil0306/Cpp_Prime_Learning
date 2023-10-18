#include "string2.h"
#include <cstring>      // 调用统计字符串长度的函数strlen
#include <cctype>       // 调用大小写转换函数

/* 首先处理一下静态变量 num_string:
    1. 这个变量的初始化 **不可以** 放在"构造函数"或"类的声明的任意位置", 因为这个变量不专属于任意一个对象, 它是共享的
    2. 静态变量是独立于对象存储的, 它于类的对象在内存中的存放区域不一样.
    3. 这种变量的初始化一般不要放在头文件中, 因为头文件可能会被个位置include, 导致初始化语句有多条, 一般只放在 定义类方法的cpp 文件中
    4. 初始化该变量时, 不需要再写 static, 需要使用作用域运算符::来指定它所属的类
*/
int String::num_strings = 0;     

int String::HowMany()           // 静态函数
{
    return num_strings;
}

String::String(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];        // new 了一块内存用于存放传入的字符串, 不然跑完这个函数之后, s里的东西就会被系统删掉
    strcpy(str, s);                 // 把s的内存拷贝到开辟的内存空间中
    num_strings++;
}

String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &st)
{
    len = st.len;
    str = new char[len + 1];        // new 了一块内存用于存放传入的字符串
    strcpy(str, st.str);            // 把st的内容拷贝一份
    num_strings++;
}

String::~String()
{
    num_strings--;
    delete[] str;       // 别漏了 [], 因为是字符数组!
} 

String & String::operator=(const String &st)
{
    if (&st == this){       // 如果是 自己 赋值给 自己, 则不需要执行任何操作
        return *this;
    }
    delete [] str; // 因为要把临时的对象赋值给原有对象, 而且原来的对象是new出来, 故需要先删除原对象, 防止内存泄露
    len = st.len;
    str = new char[len + 1];    // 重新开辟地址, 用来存储st对象里的内容
    strcpy(str, st.str);
    return *this;       // 返回当前对象本身
}

String & String::operator=(const char *st)
{
    delete [] str; // 因为要把临时的对象赋值给原有对象, 而且原来的对象是new出来, 故需要先删除原对象, 防止内存泄露
    len = strlen(st);
    str = new char[len + 1];    // 重新开辟地址, 用来存储st对象里的内容
    strcpy(str, st);
    return *this;       // 返回当前对象本身
}

char & String::operator[](int i)        // 这里没有const
{
    return str[i];
}

const char & String::operator[](int i) const    // 这里加了const, 表示不能修改任何东西
{
    return str[i];
}

bool operator<(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) < 0);
}

bool operator>(const String &str1, const String &str2)
{
    return str1 < str2;     // 使用了上面定义的运算符重载
}

bool operator==(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream &is, String &st)
{
    char temp[String::CINLIMIT];
    is.get(temp, String::CINLIMIT); // 先捕获字符, 再拷贝到对象里
    if(is){
        st = temp;      // 调用前面重载的赋值运算符 (到这里只会捕获 String::CINLIMIT 个字符, 超出部分仍留在缓冲区)
    }
    while (is && is.get()!='\n')   // 如果输入的内容太长, 则需要清空缓存 
        continue;
    return is;
}


// 编程题2新增的5个函数
String operator+(const char *s, const String &st)
{
    String temp;

    temp.len = strlen(s) + st.len;
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, s);            // s位于操作符左侧, 所以先拷贝s的内容
    strcat(temp.str, st.str);       // 用 strcat 进行追加写

    return temp;
}

String String::operator+(const String &st)
{
    String temp;

    temp.len = len + st.len;
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, str);          // 此时当前对象在操作符左侧, 所以先拷贝str
    strcat(temp.str, st.str);       // 用 strcat 追加写

    return temp;
}

void String::stringlow()
{
    for (int i = 0; i < len; i++){
        str[i] = tolower(str[i]);
    }
}

void String::stringup()
{
    for (int i = 0; i < len; i++){
        str[i] = toupper(str[i]);
    }
}

int String::has(char c) const
{
    int count = 0;
    for (int i = 0; i < len; i++){
        if(str[i] == c)
        {
            count++;
        }
    }

    return count;
}