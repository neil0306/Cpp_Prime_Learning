/*
    类的成员函数实现
*/
#include <iostream>
#include <cstring>
#include "stock20.h"

using namespace std;

Stock::Stock()
{
    company = nullptr;
    shares = 0;
    share_val = total_val = 0.0;
}

Stock::Stock(const char *co, long n, double price)
{
    company = new char[strlen(co) +1];
    strcpy(company, co);

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
    delete[] company;
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

ostream & operator<<(ostream &os, const Stock &s)       // show函数改成运算符重载
{
    os << "Company: " << s.company << endl;
    os << "Shares: " << s.shares << endl;
    os << "Share price: " << s.share_val << endl;
    os << "Total worth: " << s.total_val << endl;
    return os;
}

const Stock& Stock::topval(const Stock &s) const 
{
    if(s.total_val > total_val){    // total_val 等价于 this->total_val
        return s;
    }
    else{
        return (*this);
    }
}