#ifndef __STACK_H__
#define __STACK_H__

// typedef int Item;  // 通过typedef来实现简单的数据类型管理, 要修改数据类型时只要修改这里即可

template <class T>   // 告诉编译器下面的类是一个模板类, T用来替换用户指定的具体类型
class Stack
{
    private:
        enum{MAX = 10};     // 用枚举类型来实现常量
        // Item items[MAX];    // Item 是一个类型别名, 用来实现统一更换数据类型
        T items[MAX];
        int top;            // 栈顶指针
    public:
        Stack();            // 构造函数
        bool isEmpty() const;  // 栈是否为空 [const 成员函数, 不修改内部的数据]
        bool isFull() const;    // 栈是否满 [const 成员函数, 不修改内部的数据]
        // bool push(Item &item);  // 入栈
        // bool pop(Item &item);   // 出栈
        bool push(T &item);  // 入栈
        bool pop(T &item);   // 出栈
};

// ----------------- 下面是模板类的成员函数实现 -------------------
template <class T>
Stack<T>::Stack()
{
    top = 0;    // 初始化栈顶指针, 栈顶指针永远指向栈的 "下一个元素位置"
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return 0 == top;  // 如果为0则表明当前栈为空
}

template <class T>
bool Stack<T>::isFull() const 
{
    return top == MAX;
}

template <class T>
bool Stack<T>::push(T &item)
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

template <class T>
bool Stack<T>::pop(T &item)
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

#endif
