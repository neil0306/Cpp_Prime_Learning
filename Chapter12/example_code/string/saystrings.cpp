#include <iostream>
#include "string.h"

const int MAXLENGTH = 81;

int main(void)
{
    String name;
    cout << "Hi, what is your name? " << endl;
    cin >> name;        // 调用了重载的输入运算符
    cout << name << ", please enter a string." << endl;
    
    // 输入内容, 赋值到新的对象
    String saystrings;
    char temp[MAXLENGTH];
    cin.get(temp, MAXLENGTH);
    while(cin && cin.get() != '\n') // 超出指定长度范围时清空缓冲区
        continue;
    saystrings = temp;              // 调用了重载的赋值运算符

    cout << "Here is your sayings: " << endl;
    cout << saystrings[0] << ": " << saystrings << endl;    // 调用了重载的输出运算符

    // 测试长度比较函数
    String str = "Hello World!"; 
    if(saystrings.length() < str.length())
        cout << "str is longer." << endl;
    else
        cout << "saystrings is longer." << endl;
    
    if(saystrings < str)        // 调用重载的比较运算符, 内部使用的是 strcmp(), 它会一个个字符比较, 如果第一个字符已经有比较结果, 则不会继续进行比较
        cout << "saystrings's first letter is smaller than str's." << endl;
    else
        cout << "saystrings's first letter is bigger than str's." << endl;

    // 测试静态函数, 打印一共有多少个对象
    cout << "This program used " << String::HowMany() << " objects." << endl;

    return 0;
}
