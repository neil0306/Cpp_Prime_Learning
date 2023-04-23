#include <iostream>
using namespace std;    // 作用域在整个文件中

void simon(int n);      // 函数声明

int main(void)
{
    // using namespace std;   //(作用域只在这个函数体里)注释掉
    simon(3);           // 调用函数

    cout << "Pick an integer: ";   // 没有使用 endl, 不会换行

    int count; 
    cin >> count;
    simon(count);
    
    cout << "done." << endl;

    return 0;   // 返回0给操作系统, 表示程序跑到这里的时候, 告诉系统程序是正常结束的.
}

void simon(int n)           // 函数头 (函数定义的一部分)
{                           // 函数体 (函数定义的一部分)    
    // using namespace std;     // (作用域只在这个函数体里)注释掉
    cout << "Simon says touch your toes "
         << n
         << " times."
         << endl;
}