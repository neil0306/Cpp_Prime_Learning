/*
    用链表来模拟队列(银行排队的队列)
*/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

class Customer
{
    private:
        long arrive;            // 开始操作ATM的时间(单位:秒)
        int processtime;        // 操作ATM机的总时间

    public:
        Customer(){arrive = processtime = 0; }
        void set(long when);                    // 设置开始操作ATM的时间
        long when() const {return arrive;}      // 用来查询开始操作ATM的时间
        int ptime() const{return processtime;}  // 用来查询操作ATM的总时间
};

typedef Customer Item;     // 用来统一改变链表节点的数据类型, 这里用自定义的类型作为链表节点数据类型

class Queue
{
    private:
        enum{Q_SIZE = 10};      // 通过枚举来定义常量, 此时枚举类型是匿名的
        struct Node{Item item; Node *next;};  // 注意next指针是一个结构体指针
        Node *front;      // 头结点
        Node *rear;       // 尾结点
        int items;        // 记录队列中有多少个节点
        const int qsize;        // 队列最大长度(不希望被修改)

    public:
        Queue(int qs = Q_SIZE);
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        int queueCount() const;
        bool enqueue(const Item &item); // 入队列
        bool dequere(Item &item);       // 出队列, 出队列的节点要赋值给 item, 所以不加const

};

#endif //!__QUEUE_H__
