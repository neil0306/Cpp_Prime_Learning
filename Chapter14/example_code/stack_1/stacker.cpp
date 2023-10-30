#include <iostream>
#include <cctype>       // 为了使用 toupper()
#include <string>

#include "stack.h"

using namespace std;

const int Num = 10;

int main(void)
{
    // 下面这个例子是将 "指针存入到栈中", 而不是存放字符串进去!
    int nextIn = 0;
    int process = 0;
    const char *in[Num] = {     // 这个数组的每个元素都是一个指针常量, 每个指针常量指向一个字符串
        "1: Hank",
        "2: Kiki",
        "3: Betty",
        "4: Ian",
        "5: Wolf",
        "6: Portia",
        "7: Joy",
        "8: Xav",
        "9: Juan",
        "10: Misha"
        };
    
    Stack<const char *> st;       // 实例化的时候, 指针栈里面的指针限定为 const 指针

    while(!st.isFull()){
        st.push(in[nextIn++]);    // 指针入栈, nextIn++在入栈之后才自增
    }

    const char *out[Num];         // 指针数组, 存放出栈的字符串常量(指针)
    while(!st.isEmpty()){
        st.pop(out[process++]);     // 出栈时, 每次出栈的元素存入到 out 指针数组
    }

    // 打印出栈的内容, 要按照 10->1 的顺序输出
    for (int i = 0; i < Num; i++){
        cout << out[i] << endl;   // out[i] 是一个字符串常量(也就是 const char * 指针!)
    }
    return 0;
}