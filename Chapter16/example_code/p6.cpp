#include <iostream>
#include <queue>
#include <cstdlib>

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

void Customer::set(long when)
{
    arrive = when;
    processtime = rand() % 3 + 1;       // 这里只是模拟, 所以真正的操作时间是个随机值(限制在3分钟以内).
}

int main(void)
{
    int qs;
    Item temp;      // 对应为 Customer 类的对象
    long i = 0;
    int customers = 0;

    cout << "Enter maximum size of queue: ";
    cin >> qs;

    // Queue line(qs);     // 初始化一个队列
    queue<Item> line;

    // 往队列填充内容
    while(line.size() != qs)  // while(!line.isFull())
    {
        temp.set(i++);        // 先使用i, 再对i增加
        line.push(temp);      // line.enqueue(temp);
        customers++;
    }
    cout << "Customers: " << customers << endl;

    // 出队列
    while(!line.empty())       // while(!line.isEmpty())
    {
        temp = line.front();   // 这里的front只是取元素, 没有删除, 所以还需要pop一下
        line.pop(); 
        customers--;
    }
    cout << "Now Customers: " << customers << endl;

    return 0;
}