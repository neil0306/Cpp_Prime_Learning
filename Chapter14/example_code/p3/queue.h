#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <string>

using namespace std;

class Worker
{
    private:
        string fullname;
        long id;
    public:
        Worker() : fullname("none one"), id(0){}
        Worker(const string &s, long n) : fullname(s), id(n){}
        ~Worker(){}
        void Set();
        void Show() const;
};

template <typename T>
class Queue
{
    private:
        enum{Q_SIZE = 10};      // 通过枚举来定义常量, 此时枚举类型是匿名的
        struct Node{T item; Node *next;};  // 注意next指针是一个结构体指针
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
        bool enqueue(const T &item); // 入队列
        bool dequere(T &item);       // 出队列, 出队列的节点要赋值给 item, 所以不加const

};

template<class T>
Queue<T>::Queue(int qs) : qsize(qs)        // 这是 "成员初始化列表" 的赋值方式, 专门用于 const 变量在构造过程中进行初始化
{
    front = rear = nullptr; // 头,尾结点指针
    items = 0;      // 记录节点个数
}

// 当队列使用完之后, 如果仍有元素没有出队, 则需要靠析构函数进行内存释放
template<class T>
Queue<T>::~Queue()
{
    while(front != nullptr){
        Node * temp = front;     // 1. 取出即将释放的节点
        front = front->next;     // 2. 移动链表头到下一个位置, 防止丢失链表
        delete temp;             // 3. 释放节点
    }
}

template<class T>
bool Queue<T>::isEmpty() const
{
    return items == 0;
}

template<class T>
bool Queue<T>::isFull() const
{
    return items == qsize; 
}

template<class T>
int Queue<T>::queueCount() const
{
    return items;
}

// 入队操作是在链表尾部增加节点
template<class T>
bool Queue<T>::enqueue(const T &item)
{
    // 入队需要先判断是否为满
    if(isFull())
    {
        return false;
    }

    // 队列没有满的前提下才新增节点
    Node *add = new Node;   // 动态开辟新节点
    add->item = item;       // 新节点的数据赋值
    add->next = nullptr;    // 新增节点后面应该为空
    items++;

    if(front == nullptr){
        front = add;    // 如果一开始链表为空, 则直接把头结点设置为当前新增的节点
    }
    else{                   // 原链表本身不为空链表时, 只需要更新尾结点
        rear->next = add;   // 注意: 把原来链表的尾结点的next指向当前新增的节点, 没进行这个操作之前, rear的next节点是 nullptr
    }
    rear = add;             // 这个操作才是把原来的尾结点移动到新增节点上

    return true;
}

template<class T>
bool Queue<T>::dequere(T &item)
{
    if(isEmpty())
        return false;
    
    item = front->item;  // 队列是"先入先出", 故取头节点 (此处执行了一次拷贝)

    // 开始删节点, 更新头结点
    items--;             // 1. 更新链表数量
    Node *temp = front;  // 2. 保留原来的头结点, 用于释放内存
    front = front->next; // 3. 把当前的头结点移动到下一个位置
    delete temp;         // 4. 删除原来不要的节点

    // 更新尾结点
    if (items == 0){
        rear = nullptr;
    }

    return true;
}

#endif //!__QUEUE_H__
