#include <iostream>
using namespace std;

int main(void)
{
    char ch;
    cin.get(ch);
    while( ch != '.')
    {
        if (ch == '\n')     // 当输入的是回车时, 直接输出回车
            cout << ch;
        else
            cout << ++ch;   // 其他情况下, 输出下一个字符 (++ch是先把字符的ASCII码加1, 然后输出)
            // cout << ch + 1;    // 用这种方法+1的话, 会首先把字符转成ASCII码, 然后+1, 此时char型会变成整型(数据类型提升), 然后输出数字
        cin.get(ch);
    }

    cout << "\nPlease excuse the slight confusion.\n";   // 书本的语句

    return 0;
}