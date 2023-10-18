#ifndef __STACK_H__
#define __STACK_H__

typedef unsigned long Item;  // 通过typedef来实现简单的数据类型管理, 要修改数据类型时只要修改这里即可

class Stack
{
    private:
        enum{MAX = 10};     // 用枚举类型来实现常量
        // Item items[MAX];    // Item 是一个类型别名, 用来实现统一更换数据类型
        Item * pitems;      // items改成指针, 用动态分配内存的方式实现
        int size;           // 用来记录一共可以存放多少个元素
        int top;            // 栈顶指针
    public:
        Stack(int n = MAX);            // 构造函数
        Stack(const Stack &s);         // 复制构造
        ~Stack();

        bool isEmpty() const;   // 栈是否为空 [const 成员函数, 不修改内部的数据]
        bool isFull() const;    // 栈是否满 [const 成员函数, 不修改内部的数据]
        bool push(Item &item);  // 入栈
        bool pop(Item &item);   // 出栈

        // 养成习惯, 但凡写了 "复制构造函数", 赋值运算符就一定要重载
        Stack & operator=(const Stack &s);
};

#endif
