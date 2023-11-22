#include <iostream>

using namespace std;

const int Limit = 255;

int main(void)
{
    char input[Limit];
    cout << "Enter a string for getline() processing: " << endl;
    // cin.getline(input, Limit);      // 两个参数的版本: 遇到'\n' 或者读取 Limit 个字符之后结束读取
    cin.getline(input, Limit, '#');     // 三个参数版本: 第三个参数是指定结束读取的字符
    cout << "Here is your input: " << endl;
    cout << input << endl;

    cout << " ------- " << endl;

    char ch;
    cin.get(ch);        // 此时的效果是: 跳过指定的分隔符('#'), 读取下一个字符并放进ch中
    cout << "The next input character is: " << ch << endl;

    // 用 ignore 清除缓冲区的残留元素
    cin.ignore(Limit, '\n');    // 忽略掉当前缓冲区中 Limit 个字符, 或者 忽略掉从当前缓冲区起始位置到第一个'\n'的字符

    cout << " ------- " << endl;
    cout << "Enter a string for get() processing: " << endl;
    cin.get(input, Limit, '#');         // 三个参数的版本. 对比输出可以确认: get方法是不会丢弃分割符的
    cout << "Here is your input: " << input << endl;

    cin.get(ch);
    cout << "The next input character is: " << ch << endl;  // 捕获到前面指定的分割符 '#'

    return 0;
}