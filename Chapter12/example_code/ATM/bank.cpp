#include <iostream>
#include "queue.h"

using namespace std;

int main(void)
{
    int qs;
    Item temp;      // 对应为 Customer 类的对象
    long i = 0;
    int customers = 0;

    cout << "Enter maximum size of queue: ";
    cin >> qs;

    Queue line(qs);     // 初始化一个队列

    // 往队列填充内容
    while(!line.isFull())
    {
        temp.set(i++);      // 先使用i, 再对i增加
        line.enqueue(temp);
        customers++;
    }
    cout << "Customers: " << customers << endl;

    // 出队列
    while(!line.isEmpty())
    {
        line.dequere(temp);
        customers--;
    }
    cout << "Now Customers: " << customers << endl;

    return 0;
}
