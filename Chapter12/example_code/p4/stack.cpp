#include "stack.h"

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = 0;    // 初始化栈顶指针, 栈顶指针永远指向栈的 "下一个元素位置"
}

Stack::Stack(const Stack &s)     //复制构造
{
    // 1. 先分配当前对象的存储位置
    pitems = new Item[s.size];
    // 2. 复制内容 (由于类型不同, 就只能用最基础的循环来逐个实现)
    for (int i = 0; i < s.size; i++){
        pitems[i] = s.pitems[i];
    }
    size = s.size;
    top = s.top;
}

Stack::~Stack()
{
    delete[] pitems;
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

        pitems[top++] = item;
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

        item = pitems[--top];
        return true;
    }
    else{
        return false;
    }
}

Stack & Stack::operator=(const Stack &s)
{
    // 1. 检查自我赋值
    if(this == &s){
        return *this;
    }
    // 2. 释放当前对象以前存储的东西
    delete [] pitems;
    // 3. 重新开辟空间&拷贝传入对象的内容到当前对象
    pitems = new Item[s.size];
    for (int i = 0; i < s.size; i++){
        pitems[i] = s.pitems[i];
    }
    size = s.size;
    top = s.top;

    // 4. 返回当前对象
    return *this;
}
