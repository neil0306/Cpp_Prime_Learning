/*
    类的声明
*/
#ifndef __STOCH_00_H__
#define __STOCH_00_H__

#include <string>

class Stock
{
    private:  // 私有部分, 只有public里面的成员才能访问这部分内容(一般private的成员都是通过 public 间接访问的)
        std::string company;    // 公司名
        long shares;            // 股票数量
        double share_val;       // 股票单价
        double total_val;       // 股票总价值

        // 计算总资产
        void setTotal() 
        {
            total_val = shares * share_val;
        }

    public:   // 公有部分, 任何代码都可以直接访问
        //Stock(const std::string &co, long n, double price);  // 原来的 acquire 函数改写为自定义的构造函数
        Stock(const std::string &co = "Error", long n = 0, double price = 0.0); // 测试第一种默认构造函数
        // Stock(); // 测试第二种默认构造函数

        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();


};  // 别忘记分号, 这和结构体的语法是相同的

#endif // __STOCH_00_H__