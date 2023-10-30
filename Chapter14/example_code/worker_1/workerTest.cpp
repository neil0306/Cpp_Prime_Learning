#include <iostream>
#include <cstring>
#include "worker.h"

using namespace std;

const int SIZE = 3;

int main(void)
{
    Worker *lolas[SIZE];        // 用间接基类(祖先基类)来管理所有的派生类
    int i;
    char choice;
    for (i = 0; i < SIZE; i++){
        cout << "Enter the employee category: " << endl
            << "w: Waiter   s: Singer   t: Singing Waiter    q: quit" << endl;
            cin >> choice;
        
        // 判断输入是否合理, 不合理则继续输入
        while(strchr("wstq", choice) == nullptr){      // strchr 用于查找字符串中的一个字符，并返回该字符在字符串中第一次出现的位置。
            cout << "Please enter a character from w, s, t, q: ";
            cin >> choice;
        }

        if (choice == 'q'){
            break;
        }

        // 用默认构造函数创建对应的类对象的存储空间
        switch (choice){
        case 'w':
            lolas[i] = new Waiter;
            break;
        case 's':
            lolas[i] = new Singer;
            break;
        case 't':
            lolas[i] = new SingingWaiter;
            break;
        }
        while(cin.get() != '\n') {};       // 干掉回车
        
        lolas[i]->Set();    // 填充信息到对应的类
    }

    if (i > 0){
        cout << "\nHere is your staff: " << endl;
        for(i = 0; i < SIZE; i++){
            lolas[i]->Show();
            cout << endl;
        }

        // 释放内存空间
        for(i = 0; i < SIZE; i++){
            delete lolas[i];
        }
    }

    return 0;
}
