#include <iostream>

/*
由于编译器是 "从上往下编译" 的, 因此, 如果我们如果有自己定义的函数, 
就必须把函数声明放在 main 函数之前, 不然编译的时候, 会在main里报错, 说找不到函数
*/
void simon(int n);      // 函数声明

int main(void)
{
    using namespace std;
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
    using namespace std;
    cout << "Simon says touch your toes "
         << n
         << " times."
         << endl;
}