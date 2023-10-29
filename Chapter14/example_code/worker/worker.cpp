#include "worker.h"


// 基类 Worker
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

// 派生类 Waiter
void Waiter::Set()
{
    // 派生类, 首先需要调用一下基类的对应方法, 以确保基类被赋值
    Worker::Set();
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while(cin.get() != '\n');
}

void Waiter::Show() const
{
    Worker::Show();     // 先完成基类的输出
    cout << "Panache rating: " << panache << endl;
}

// 派生类 Singer
const char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};        // 静态成员! 需要另外初始化

void Singer::Set()
{
    Worker::Set();
    int i;
    for (i = 0; i < Vtypes; i++){
        cout << i << ": " << pv[i];
        if(i%4 == 3){
            cout << endl;
        }
    }
    if(i%4 != 0){
        cout << endl;
    }

    cout << "Please enter a value >=0 and <" << Vtypes << endl;
    cin >> voice;

    while(cin.get() != '\n');
}

void Singer::Show() const
{
    Worker::Show();
    cout << "Voice range: " << pv[voice] << endl;
}
