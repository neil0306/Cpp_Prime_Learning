#ifndef __BRASS_H__
#define __BRASS_H__

#include <iostream>
#include <string>
using namespace std;

class Brass
{
    private:
        string fullname;        // 用户名
        long accNum;           // 账户
        double balance;         // 存款金额
    public:
        Brass(const string &s = "NullBody", long an = -1, double bal = 0.0);        // 完成创建账号(初始化数据成员)

        // 养成习惯, 基类的析构函数一定要定义成 虚函数!!!!
        virtual ~Brass(){}

        void Deposit(double amt);
        virtual void Widthdraw(double amt);
        double Balance() const;
        virtual void ViewAcc() const;       // 只显示当前账户里有多少钱
};

class BrassPlus : public Brass      // 派生类
{
    private:
        double maxLoan;         // 贷款额度
        double rate;            // 利率
        double owesBank;        // 本金 + 利息
    public:
        BrassPlus(const string &s = "NullBody", long an = -1, double bal = 0.0, double ml = 500.0, double r = 0.11125);
        BrassPlus(const Brass &ba, double ml = 500.0, double r = 0.11125);
        virtual void ViewAcc() const;         // 显示账户有多少钱, 显示欠款和贷款额度
        virtual void WidthDraw(double amt);
        void ResetMax(double m){maxLoan = m;}
        void ResetRate(double r){rate = r;}
        void ResetOwes(){owesBank = 0.0;}
};

#endif //!__BRASS_H__
