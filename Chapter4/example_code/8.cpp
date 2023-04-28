#include <iostream>
#include <string>

int main(void)
{
    using namespace std;

    string str1 = "penguin";
    string str2;

    cout << "You can assign one string object to another: str2 = str1\n";
    str2 = str1; 
    cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

    cout << "You can assign a C-style string to a string object.\n";
    str2 = "buzzard";               // 用C语言中, 字符串的方式进行重新赋值
    cout << "str2 = " << str2 << endl;

    cout << "You can concatenate strings: str3 = str1 + str2\n";
    string str3;
    str3 = str1 + str2;             // 拼接
    cout << "str3 = " << str3 << endl;                       // "penguinbuzzard"

    cout << "You can append strings.\n";  
    str1 += str2;                   // 追加
    cout << "str1 += str2 yields str1 = " << str1 << endl;   //"penguinbuzzard"

    str2 += " for a day";           // 追加 字符串常量
    cout << "str2 += \" for a day\" yields str2 = " << str2 << endl;  //"buzzard for a day"


    return 0;
}