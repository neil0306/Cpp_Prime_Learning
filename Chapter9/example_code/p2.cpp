/*
    局部静态变量 -- 代码块中使用static
*/

#include <iostream>
#include <string>
using namespace std;

void strCount(const string str);

int main(void)
{
    string input;
    char next;

    cout << "Enter a line (less than 9 chars):" << endl;

    getline(cin,input);
    while(input != ""){                 // 判断是否真的有输入
        // 捕获单个字符, 用来检测是不是因为输入回车才结束输入 (cin.get()遇到回车时, 不仅会结束输入, 还会把回车存放在缓冲区)
        cin.get(next);
        strCount(input);        // 统计一共捕获了多少个字符
        cout << "Enter next line (empty line to quit)" << endl;
        getline(cin, input);
    }
    cout << "Bye!" << endl;     // 此时输入的是空行.

    return 0;
}

void strCount(const string str)
{
    static int total = 0;       // 局部静态变量(只会初始化一次, 多次调用strCount也不会反复初始化)
    int count = 0;              // 局部变量(每次都会初始化)

    count = str.size();
    total += count;             // 统计整个程序一共输入了多少个字符

    cout << count << " characters" << endl;
    cout << total << " characters in total." << endl;
    cout << "----------- \n"; 
}