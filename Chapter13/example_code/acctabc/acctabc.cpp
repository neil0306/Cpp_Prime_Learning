#include "acctabc.h"

// ------ 抽象基类 ------
Acctabc::Acctabc(const string &s, long an, double bal)
{
    fullname = s;
    accNum = an;
    balance = bal;
}

void Acctabc::Deposit(double amt)
{
    if (amt < 0){
        cout << "Negative deposit is not allowed!" << endl;
    }
    balance += amt;
}

void Acctabc::Withdraw(double amt)
{
    balance -= amt;
}


// ------ 派生类 Brass ------
void Brass:: Withdraw(double amt)
{
	if(amt < 0)
		cout << "Withdraw amount must be positive." << endl;
	else if(amt <= Balance())
		Acctabc::Withdraw(amt);
	else
		cout << "Withdraw amount exceeded your balance!" << endl;
}


void Brass::ViewAcct() const
{
    cout << "Client: " << FullName() << endl;
    cout << "Account Number: " << AccNum() << endl;
    cout << "Balance: $" << Balance() << endl;
}

// ------ 派生类 BrassPlus ------
BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : Acctabc(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Acctabc &ba, double ml, double r) : Acctabc(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const         // 虚函数在定义时不需要再加 virtual
{
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AccNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum Loan: $" << maxLoan << endl;
    cout << "Loan Rate: " << rate << endl;
    cout << "Owed to bank: $" << owesBank << endl;
}

void BrassPlus::Withdraw(double amt)  // 虚函数在定义时不需要再加 virtual
{
    double bal = Balance();     // 虽然没有在派生类中定义balance, 但是基类中已经有这个函数(且输入public), 直接使用即可

    if(amt <= bal){             // 余额充足, 直接取钱
        Acctabc::Withdraw(amt);
    }
    else if(amt <= bal + maxLoan - owesBank){       // 注意此时余额已经不够了, 余额 + 透支额度 - 已有贷款 = 当前能取的金额
        double advance = amt - bal;
        owesBank = advance * (1.0 + rate);          // 更新一下总欠款
        cout << "Bank Advance: $" << advance << endl;       // 显示本次取钱需要向银行借多少钱
        cout << "Finance Charge: $" << advance * rate << endl;      // 显示加上手续费之后一共多少钱
    
        Deposit(advance);           // 向银行借完钱, 刷新可取钱的余额
        Acctabc::Withdraw(amt);      // 调用基类的widthdraw
    }
    else{
        cout << "Credit limit exceeded!" << endl;
    }
}
