#include <iostream>
#include <cctype>       // 为了使用 toupper()
#include "stack.h"

using namespace std;

const int MAX = 5;
int main(void)
{
    Stack st(MAX);
    Item item;

    for (int i = 0; i < MAX; i++){
        cout << "Enter a number you want to push to stack: ";
        cin >> item;
        while(cin.get() != '\n');    // 消耗掉多余的内容, 循环体里啥都不干
        st.push(item);      // 入栈
    }

    Stack st_new(st);       // 复制构造
    for (int i = 0; i < MAX; i++){
        st_new.pop(item);
        cout << item << " is poped!" << endl;
    }

    return 0;
}