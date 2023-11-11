#include "queue.h"

void Worker::Set()
{
    cout << "Enter worker's full name: " ;
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while(cin.get()!= '\n');        // 但凡字符串和数字交替输入, 就要写这个语句, 清掉缓冲区的回车
}

void Worker::Show() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}
