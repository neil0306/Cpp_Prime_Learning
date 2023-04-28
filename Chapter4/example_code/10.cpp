#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
    using namespace std;

    char charr1[20];     // 声明的时候, 向系统申请了 20 个字符大小的内存空间
    string str;

    cout << "Length of string in charr1 before input: " << strlen(charr1) << endl; // 由于前面只进行了声明, 没有初始化, 
                                                                                   // 这里统计的长度是不确定的, strlen() 会从数组的起始地址开始统计, 直到遇到一个空字符 \0 为止.
                                                                                   // 也就是说, 统计出来的值是不确定的, 可能是 0, 也可能是一个很大的值(超过申请的数组空间).

    cout << "Length of string in str1 before input: " << str.size() << endl;      // string 类在没有初始化的情况下, size() 会自动设置为0

    cout << "Enter a line of text:\n";
    cin.getline(charr1, 20);
    cout << "You entered: " << charr1 << endl;

    cout << "Enter another line of text:\n";
    getline(cin, str);  // cin 是一个对象, cin.getline() 是一个函数, getline() 是一个函数, 但是 cin.getline() 来自于 istream 类, getline() 来自于 string 类
    cout << "You entered: " << str << endl;

    cout << "Length of string in charr1 after input: " << strlen(charr1) << endl; 
    cout << "Length of string in str1 after input: " << str.size() << endl;      

    return 0;
}