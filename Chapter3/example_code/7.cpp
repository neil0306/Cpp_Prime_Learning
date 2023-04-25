#include <iostream>
using namespace std;

int main(void)
{
    // const int toes;  // 没有进行初始化, 但是这块内存里其实本身已经有(垃圾)值, 后面不允许再更改的了, 
    //                 //这种写法等于是定义了一个垃圾变量, 编译也会报错的.
    // toes = 10;       // 上一句代码已经定义了toes为常量(值被自动初始化为内存块里的垃圾值了), 这里再赋值就是错误的了.
    
    const int toes = 10;  // 这样就是正确的写法了
    
    return 0;
}