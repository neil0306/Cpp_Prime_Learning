#include "worker.h"

// 基类 Worker
void Worker::Get()
{
    cout << "Enter worker's full name: " ;
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while(cin.get()!= '\n');        // 但凡字符串和数字交替输入, 就要写这个语句, 清掉缓冲区的回车
}

void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

// 派生类 Waiter
void Waiter::Get()
{
    // 派生类, 首先需要调用一下基类的对应方法, 以确保基类被赋值
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while(cin.get() != '\n');
}

void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Set()
{
    Worker::Get();
    Waiter::Get();
}

void Waiter::Show() const
{
    Worker::Data();
    Waiter::Data();
}

// 派生类 Singer

// 首先初始化静态成员
const char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};        // 静态成员! 需要另外初始化

void Singer::Get()
{
    int i;
    for (i = 0; i < Vtypes; i++){
        cout << i << ": " << pv[i] << " ";
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

void Singer::Data() const
{
    cout << "Voice range: " << pv[voice] << endl;
}

void Singer::Set()
{
    Worker::Get();
    Singer::Get();
}

void Singer::Show() const
{
    Worker::Data();
    Singer::Data();
}


// 多重继承的 SingingWaiter
void SingingWaiter::Set()
{
    Worker::Get();
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Show() const
{
    Worker::Data();
    Waiter::Data();
    Singer::Data();
}
