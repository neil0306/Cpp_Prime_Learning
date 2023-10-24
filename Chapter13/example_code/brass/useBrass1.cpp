#include "brass.h"
#include <iostream>

using namespace std;

int main(void)
{
    Brass rick("Rick", 123456, 4000);
    BrassPlus jack("Jack", 654321, 3000);

    // 使用对象调用相应的方法
    rick.ViewAcc();         // 调用基类方法
    cout << endl;
    jack.ViewAcc();         // 调用派生类方法
    cout << endl;
    
    // 测试透支功能
    cout << "Deposit $1000 into the Jack Account. " << endl;
    jack.Deposit(1000);
    cout << "New balance: $" << jack.Balance() << endl;

    cout << "Widthdraw 4200 from the Rick Account." << endl;
    rick.Widthdraw(4200);       // 基类对象, 不允许透支

    cout << "-----------" << endl;
    cout << "Widthdraw 4200 from the Jack Account." << endl;
    jack.WidthDraw(4200);       // 派生类对象, 可以透支
    jack.ViewAcc();             // 打印透支后的情况

    return 0;
}
