/*
    写一个函数, 返回一个字符串中出现了多少个指定的字符.
*/
#include <iostream>

using namespace std;

unsigned int c_in_str(const char *str, char ch);

int main(void)
{
    char mmm[15] = "minimum";
    // char *wail = "ululate"; //  这样写会报错的, 因为"ululate"此时是 const 类型, 如果允许的话, 就会存在 wail 指针修改了常量的风险
    const char *wail = "ululate";   // 还可以写成强制类型转换 char *wail = (char *) "ululate";  但是不太推荐

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');   

    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;


    return 0;
}

unsigned int c_in_str(const char *str, char ch)  // 因为我们不希望数组在这个函数中被不慎修改, 这里加一个cosnt做保护
{
    unsigned sum = 0;

    while(*str)   // 这样写表示: 一直遍历数组元素, 没有到最后一个元素就继续循环
    {
        if(*str == ch)
            sum++;
        str++;    // 移动到下一个元素, 遍历到最后一个元素时, 它的内容是一个空白字符 '\0'
    }

    return sum;
}