#include "brass.h"
#include <iostream>

using namespace std;
const int CLIENTS = 3;

int main(void)
{
    Brass *p_client[CLIENTS];
    string temp;
    long temp_num;
    double temp_bal;
    int kind = 1;
    for (int i = 0; i < CLIENTS; i++){
        // 让用户输入开户信息
        cout << "Enter the client's name: ";
        getline(cin, temp);     // 因为可能存在空格, 所以需要捕获一整行
        cout << "Enter client's account number: ";
        cin >> temp_num;
        cout << "Enter openning balance: $";
        cin >> temp_bal;
        cout << "Enter 1 for Brass account or enter 2 for BrassPlus account: ";
    
        while(cin >> kind && (kind != 1 && kind != 2)){
            cout << "Enter either 1 or 2: ";
        }
        // 创建对象指针
        if (kind == 1){
            p_client[i] = new Brass(temp, temp_num, temp_bal);        // 对类使用new, 会触发构造函数
        }
        else{
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the rate: ";
            cin >> trate;
            p_client[i] = new BrassPlus(temp, temp_num, temp_bal, tmax, trate);
        }

        // 敲完 1 或 2之后, 缓冲区还有一个回车符
        while(cin.get() != '\n');
    }
    cout << endl;

    // 显示信息
    for (int i = 0; i < CLIENTS; i++){
        // 这里的 ViewAcc 函数是 virtual 的, 所以此时会根据指针所指对象的类型调用相应的函数
        p_client[i] -> ViewAcc();       // 通过指针访问方法, 此时 p_client 可能是Brass对象也可能是BrassPlus对象
        cout << endl;
    }

    // 有 new 就得有 delete !!
    for (int i = 0; i < CLIENTS; i++){
        delete p_client[i];
    }

    /*
        关于这里析构的说明:
            1. 在析构时, 如果是派生类对象, 则应先析构派生类, 再析构基类
            2. 如果派生类的析构函数不是 virtual 的, 则编译器**只会**调用 "指针类型" 对应的析构函数, 也就是说, 如果Brass的析构函数不是virtual的, 那么在这里只有Brass类型的析构函数会被调用
                此时, 哪怕 p_client[i] 指向一个派生类对象, 也不会触发派生类的析构函数!!!
                此时, 需要小心 派生类 里面是否有东西没有析构掉!!!
        
        因此, 如果一个类作为基类使用, 它的析构函数一定要写成虚函数!!!
    */
    return 0;
}
