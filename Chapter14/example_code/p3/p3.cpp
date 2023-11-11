#include <iostream>

#include "queue.h"

using namespace std;

int main(void)
{
    Queue<Worker *> wk(3);         // 队列里存放的是 Worker 类对象的指针

    Worker w1;
    w1.Set();
    w1.Show();
    wk.enqueue(&w1);                // 把Worker类对象的地址入队列

    cout << "Now Queue has: " << wk.queueCount() << " items" << endl;   // 显式当前队列中有多少元素

    Worker w2;
    w1.Set();
    w1.Show();
    wk.enqueue(&w2);                // 把Worker类对象的地址入队列
    cout << "Now Queue has: " << wk.queueCount() << " items" << endl;   // 显式当前队列中有多少元素

    Worker w3;
    w1.Set();
    w1.Show();
    wk.enqueue(&w3);                // 把Worker类对象的地址入队列
    cout << "Now Queue has: " << wk.queueCount() << " items" << endl;   // 显式当前队列中有多少元素

    return 0;
}