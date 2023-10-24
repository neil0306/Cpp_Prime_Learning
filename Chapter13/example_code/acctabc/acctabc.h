#ifndef __ACCTABC_H__
#define __ACCTABC_H__

#include <iostream>
#include <string>
using namespace std;

class Acctabc
{
    private:    // 只要是数据成员, 就设置为私有的
        string fullname;        // 用户名
        long accNum;            // 账户
        double balance;         // 存款金额

    protected:  // 不希望类对象能直接访问但派生类能访问的函数定义为 protected
        const string & FullName() const {return fullname;}
        long AccNum() const {return accNum;}
    public:
        Acctabc(const string &s, long an = -1, double bal = 0.0);

    public:
        void Deposit(double amt);                   // 存款操作是一样的, 所以不用定义为虚函数
        virtual void Withdraw(double amt) = 0;     // 派生类中有不一样的操作, 故定义为纯虚函数
        double Balance() const {return balance;}

        virtual void ViewAcct() const = 0;                // 纯虚函数
        virtual ~Acctabc(){};       // 析构函数要定义为虚函数
};

class Brass : public Acctabc
{
    public:
        Brass(const string &s = "NullBody", long an = -1, double bal = 0.0) : Acctabc(s, an, bal){}

        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;       // 只显示当前账户里有多少钱
        virtual ~Brass(){}  // 不做基类时, 写成虚析构函数也不会报错
};

class BrassPlus : public Acctabc      // 派生类
{
    private:
        double maxLoan;         // 贷款额度
        double rate;            // 利率
        double owesBank;        // 本金 + 利息
    public:
        BrassPlus(const string &s = "NullBody", long an = -1, double bal = 0.0, double ml = 500.0, double r = 0.11125);
        BrassPlus(const Acctabc &ba, double ml = 500.0, double r = 0.11125);
        virtual void ViewAcct() const;         // 显示账户有多少钱, 显示欠款和贷款额度
        virtual void Withdraw(double amt);
        void ResetMax(double m){maxLoan = m;}
        void ResetRate(double r){rate = r;}
        void ResetOwes(){owesBank = 0.0;}
};

#endif //!__ACCTABC_H__
