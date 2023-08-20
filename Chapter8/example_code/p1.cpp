#include <iostream>
using namespace std;

void show(const char * str, int n = 0);

int main(void)
{
    show("Hello World!");
    show("Good Morning!");
    show("I love you, Rick.",8);

    return 0;
}

void show(const char * str, int n)
{
    // 定义一个静态变量, 它的可以使得在函数中定义的局部变量相当于一个"全局变量", 它只会被初始化1次.
    static int num = 0;     // 这个语句只会被调用1次
    num++;                  // 每次调用函数都会执行一次

    if (0 == n){
        cout << str << endl;
    }
    else{
        for(int i = 0; i < num; i++){
            cout << str << endl;
        }
    }

}
