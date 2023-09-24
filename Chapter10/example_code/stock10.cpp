/*
    类的成员函数实现
*/
#include <iostream>
#include "stock10.h"

Stock::Stock(const std::string &co, long n, double price)
{
    company = co;       // 直接就访问到了private里的变量
    if(n < 0){
        std::cout << "Number of shares can't be negative! " << company << " shares set to be 0!" << std::endl;
        shares = 0;
    }
    else{
        shares = n;
    }

    share_val = price;
    setTotal();     // 直接调用了 private 里的函数
}

// 定义一个析构函数
Stock::~Stock()
{
    std::cout << "Bye! " << company << std::endl;
}

void Stock::buy(long num, double price)
{
    if(num < 0){
        std::cout << "Number of shares can't be negative! Transaction aborted!" << std::endl;
    }
    else{
        shares += num;      // 买入股票, 持有数量增加 num
        share_val = price;
        setTotal();
    }
}

void Stock::sell(long num, double price)
{
    if(num < 0){
        std::cout << "Number of shares can't be negative! Transaction aborted!" << std::endl;
    }
    else if(num > shares){
        std::cout << "You can't sell more than you have! Transaction is aborted!" << std::endl;
    }
    else{
        shares -= num;
        share_val = price;
        setTotal();
    }
}

void Stock::update(double price)
{
    share_val = price;
    setTotal();
}

void Stock::show() const // 增加const 关键词, 定义为"const 成员函数"
{
    using namespace std;
    cout << "Company: " << company << endl;
    cout << "Shares: " << shares << endl;
    cout << "Share price: " << share_val << endl;
    cout << "Total worth: " << total_val << endl;
}