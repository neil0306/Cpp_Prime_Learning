#ifndef __P1_H__
#define __P1_H__

#include <string>
#include <iostream>
using namespace std;

class BankAccount 
{
    private:
        string name;
        string accountNumber;
        double balance;
    
    public:
        BankAccount(string client, string num, double bal = 0.0);          // 构造函数: 初始化
        void show(void) const;       // 显示
        void deposit(double cash);   // 存款
        void withdraw(double cash);  // 取款
};

#endif // __P1_H__
