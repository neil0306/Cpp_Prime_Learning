#include "queue.h"
#include <cstdlib>      // 为了使用rand函数而引入

Queue::Queue(int qs) : qsize(qs)        // 这是 "成员初始化列表" 的赋值方式, 专门用于 const 变量在构造过程中进行初始化
{
    front = rear = nullptr; // 头,尾结点指针
    items = 0;      // 记录节点个数
    // qsize = qs;     // 链表的总长度(由于定义成const类型, 这里不能再次赋值了)
}

// 当队列使用完之后, 如果仍有元素没有出队, 则需要靠析构函数进行内存释放
Queue::~Queue()
{
    while(front != nullptr){
        Node * temp = front;     // 1. 取出即将释放的节点
        front = front->next;     // 2. 移动链表头到下一个位置, 防止丢失链表
        delete temp;             // 3. 释放节点
    }
}

bool Queue::isEmpty() const
{
    return items == 0;
}

bool Queue::isFull() const
{
    return items == qsize; 
}

int Queue::queueCount() const
{
    return qsize;
}

// 入队操作是在链表尾部增加节点
bool Queue::enqueue(const Item &item)
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

bool Queue::dequere(Item &item)
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

void Customer::set(long when)
{
    arrive = when;
    processtime = rand() % 3 + 1;       // 这里只是模拟, 所以真正的操作时间是个随机值(限制在3分钟以内).
}
