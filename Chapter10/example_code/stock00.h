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

        void setTotal(double &total_val) 
        {
            total_val = shares * share_val;
        }

    public:   // 公有部分, 任何代码都可以直接访问
        void acquire(const std::string &co, long n, double price);
        void buy(long num, double price);
        double sell(long num, double price);
        void update(double price);
        void show();


};  // 别忘记分号, 这和结构体的语法是相同的

#endif // __STOCH_00_H__