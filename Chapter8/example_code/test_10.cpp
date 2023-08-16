/*
    本例子主要与C++的 "左值/右值引用" 相关.
        left, rigt 通常与赋值运算符相关(= , +=), 赋值运算符左侧就成为"左值", 右侧的就叫做"右值".

        巧记: 凡是能进行[取地址]操作的都是左值, 不能取地址的都是右值.
*/

#include <iostream>

using namespace std;

int main(void)
{
    int a = 10;     // a 是左值(可读可写的变量), 10 是右值(只读变量)
    int b = a;      // b 是左值(可读可写的变量), a 是右值(只读变量)

    int *p = &a;    // 能取地址, 此时的a还是左值

    // int *p = &(a+b);    // 编译时会报错(cannot take the address of an rvalue of type 'int'), 
                           // 说明(a+b) 这个整体是一个"右值", 报错信息里的关键词是 "rvalue"

    // 左值引用
    int &c = a;         // c 相当于是a的"别名", 这种引用方式叫做 "左值引用"
    // int &d = 10;        // 会报错 (initial value of reference to non-const must be an lvalue), 这是因为10是右值, 而"左值引用"要求 引用的对象一定是 "左值", 简单来讲就是 = 号右侧一定要能 "取地址"
    // int &d = (a+b);     // 同样报错(initial value of reference to non-const must be an lvalue), 原因就是 (a+b) 不是"左值", 特点就是没办法取地址.

    // 加const之后, 这种引用已经是 "常引用(阉割版引用)" 了. 此时的引用是与"一个临时变量"进行绑定的, 绑定之后, 这个引用变量只能读取数据, 无法修改数据.
    const int &d = 10;      // 加 const 之后就合法了, 因为10在内存中产生了一个 "临时变量", 这时候 d 就会和那个临时变量绑定在一起
    const int &e = (a+b);   // 加 const 之后就合法了, 因为a+b在内存中产生了一个 "临时变量", 这时候 e 就会和那个临时变量绑定在一起

    // C++ 11 中新增的 "右值引用", 编译的时候可能会有相关的版本提示.
    /*
        1. 两个 && 表示是右值引用
        2. 右值引用并不是为了取代左值引用, 它的存在是为了"移动语义", 这在析构函数中非常有用.
    */
    int &&x = 10;           // x 是右值引用
    int &&y = (a+b);        // y 也是右值引用



    return 0;
}

