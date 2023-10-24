#include "brass.h"

Brass::Brass(const string &s, long an, double bal)
{
    fullname = s;
    accNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0){
        cout << "Negative deposit is not allowed!" << endl;
    }
    balance += amt;
}

void Brass::Widthdraw(double amt)
{
    if (amt < 0){
        cout << "Widthdraw amount must be positive!" << endl;
    }
    else if(amt <= balance){
        balance -= amt; 
    }
    else {
        cout << "Widthdraw amount exceeded your balance!" << endl;
    }
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcc() const
{
    cout << "Client: " << fullname << endl;
    cout << "Account Number: " << accNum << endl;
    cout << "Balance: $" << balance << endl;
}

BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : Brass(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcc() const         // 虚函数在定义时不需要再加 virtual
{
    Brass::ViewAcc();       // 指明先调用的是基类的ViewAcc函数
    cout << "Maximum Loan: $" << maxLoan << endl;
    cout << "Loan Rate: " << rate << endl;
    cout << "Owed to bank: $" << owesBank << endl;
}

void BrassPlus::WidthDraw(double amt)  // 虚函数在定义时不需要再加 virtual
{
    double bal = Balance();     // 虽然没有在派生类中定义balance, 但是基类中已经有这个函数(且输入public), 直接使用即可

    if(amt <= bal){             // 余额充足, 直接取钱
        Brass::Widthdraw(amt);
    }
    else if(amt <= bal + maxLoan - owesBank){       // 注意此时余额已经不够了, 余额 + 透支额度 - 已有贷款 = 当前能取的金额
        double advance = amt - bal;
        owesBank = advance * (1.0 + rate);          // 更新一下总欠款
        cout << "Bank Advance: $" << advance << endl;       // 显示本次取钱需要向银行借多少钱
        cout << "Finance Charge: $" << advance * rate << endl;      // 显示加上手续费之后一共多少钱
    
        Deposit(advance);           // 向银行借完钱, 刷新可取钱的余额
        Brass::Widthdraw(amt);      // 调用基类的widthdraw
    }
    else{
        cout << "Credit limit exceeded!" << endl;
    }
}
