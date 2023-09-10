/*
    局部静态变量 -- 代码块中使用static
*/

#include <iostream>
using namespace std;

const int ArrSize = 10;

void strCount(const char *str);

int main(void)
{
    char input[ArrSize];
    char next;

    cout << "Enter a line (less than 9 chars):" << endl;

    cin.get(input, ArrSize);    // cin.get(存放输入的变量, 存放的大小)
    while(cin){                 // 用来判断cin是否真的有输入
        // 捕获单个字符, 用来检测是不是因为输入回车才结束输入 (cin.get()遇到回车时, 不仅会结束输入, 还会把回车存放在缓冲区)
        cin.get(next);
        while (next != '\n'){
            cin.get(next);      // 如果不是回车, 则说明用户输入的字符太长了, 用cin.get(next)把缓冲区的东西消耗掉
        }
        strCount(input);        // 统计一共捕获了多少个字符
        cout << "Enter next line (empty line to quit)" << endl;
        cin.get(input, ArrSize);
    }
    cout << "Bye!" << endl;     // 此时输入的是空行.

    return 0;
}

void strCount(const char *str)
{
    static int total = 0;       // 局部静态变量(只会初始化一次, 多次调用strCount也不会反复初始化)
    int count = 0;              // 局部变量(每次都会初始化)

    while(*str++){      // 记得移动指针到下一个元素
        count ++;
    }
    total += count;             // 统计整个程序一共输入了多少个字符

    cout << count << " characters" << endl;
    cout << total << " characters in total." << endl;
    cout << "----------- \n"; 
}