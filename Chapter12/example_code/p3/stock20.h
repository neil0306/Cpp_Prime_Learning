/*
    类的声明
*/
#ifndef __STOCH_20_H__
#define __STOCH_20_H__

#include <iostream>
using namespace std;

class Stock
{
    private:  // 私有部分, 只有public里面的成员才能访问这部分内容(一般private的成员都是通过 public 间接访问的)
        char * company;                                                 // 公司名, 从string对象改成指针
        long shares;            // 股票数量
        double share_val;       // 股票单价
        double total_val;       // 股票总价值

        // 计算总资产
        void setTotal() 
        {
            total_val = shares * share_val;
        }

    public:   // 公有部分, 任何代码都可以直接访问
        Stock();
        Stock(const char * co, long n, double price);                   // string类对象改成指针
        ~Stock();  // 声明一个析构函数 (第一种写法)
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        const Stock& topval(const Stock &s) const;

    // 编程题3新增的函数
    public:
        friend ostream & operator<<(ostream &os, const Stock &s);       // show函数改成重载运算符的方式


};  // 别忘记分号, 这和结构体的语法是相同的

#endif // __STOCH_20_H__