#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>
using namespace std;

typedef int Item;  // 通过typedef来实现简单的数据类型管理, 要修改数据类型时只要修改这里即可

void visit_item(Item &item);

class List
{
    private:
        enum{MAX = 10};     // 用枚举类型来实现常量
        Item items[MAX];    // Item 是一个类型别名, 用来实现统一更换数据类型
        int top;            // 列表头指针, 用栈的方式实现
    public:
        List();            // 构造函数
        bool isEmpty() const;   // 列表是否为空 [const 成员函数, 不修改内部的数据]
        bool isFull() const;    // 列表是否满 [const 成员函数, 不修改内部的数据]
        bool add(Item &item);   // 添加元素
        void visit(void (*pf)(Item &));     // 注意这里是 "函数指针" !!
};

#endif
