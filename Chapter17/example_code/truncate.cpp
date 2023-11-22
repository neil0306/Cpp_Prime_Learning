#include <iostream>

using namespace std;

const int SLEN = 10;
int main(void)
{
    char name[SLEN];
    char title[SLEN];
    cout << "Enter your name: ";
    cin.get(name, SLEN);        // 注意: 如果 cin.get() 读取整行, 它将保留 '\n' 在缓冲区中!
    if(cin.peek() != '\n' ){    // 进入这个if的条件是: 输入内容过长, name没有足够的空间读完一整行
        cout << "Sorry, we don't have enough room for " << name << endl;
    }
    cin.ignore(SLEN, '\n');         // 清空缓冲区方式1
    // while (cin.get() != '\n'){};    // 情况缓冲区方式2


    cout << "Dear " << name << ", enter your title: ";
    cin.get(title, SLEN);
    if(cin.peek() != '\n'){
        cout << "We were forced to truncate your title." << endl;
    }
    while (cin.get() != '\n'){};    // 情况缓冲区方式2

    cout << "Name: " << name << endl;
    cout << "Title: " << title << endl;
    return 0;
}