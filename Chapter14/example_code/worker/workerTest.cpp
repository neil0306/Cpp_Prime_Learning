#include <iostream>
#include "worker.h"

using namespace std;

const int LIM = 4;

int main(void)
{
    Waiter bob("Bob", 314,5);
    Singer bev("Bev", 522, 3);
    Waiter w_temp;
    Singer s_temp;


    // 用抽象基类指针管理所有派生类对象!!
    Worker *pw[LIM] = {&bob, &bev, &w_temp, &s_temp};

    // 填充后两个对象的元素
    int i;
    for (i = 2; i < LIM; i++){
        pw[i]->Set();               // Set 是虚函数, 可以动态调用对应的函数
    }

    for (i = 0; i < LIM; i++){
        pw[i]->Show();
        cout << endl;
    }

    return 0;
}
