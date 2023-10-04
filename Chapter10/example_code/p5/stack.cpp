#include "stack.h"

Stack::Stack()
{
    top = 0;    // 初始化栈顶指针, 栈顶指针永远指向栈的 "下一个元素位置"
}

bool Stack::isEmpty() const
{
    return 0 == top;  // 如果为0则表明当前栈为空
}

bool Stack::isFull() const 
{
    return top == MAX;
}

bool Stack::push(Item &item)
{
    if(top < MAX){
        // items[top] = item;  // top 指向栈的"下一个元素"的位置, 因此top这个位置是可以直接存入数据的
        // top++;      // 也可以写成 items[top++] = item;

        items[top++] = item;
        return true;
    }
    else{
        return false;
    }
}

bool Stack::pop(Item &item)
{
    if(top > 0){
        // top--;      // 把top移动到栈里最顶端的元素位置
        // item = items[top];  // 取最顶端的元素赋值到item, 作为返回值, 此时top指向的位置依旧是"栈的下一个元素位置"
        // // 上面两行也可以直接写为: item = items[--top];

        item = items[--top];
        return true;
    }
    else{
        return false;
    }
}
