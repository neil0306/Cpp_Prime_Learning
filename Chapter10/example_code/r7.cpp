#include <cstring>

class BankAccount 
{
    private:
        char name[50];
        char accountNumber[50];
        double balance;
    
    public:
        BankAccount(const char *client, const char *num, double bal = 0.0);          // 构造函数: 初始化
        void show(void) const;       // 显示
        void deposit(double cash);   // 存款
        void withdraw(double cash);  // 取款
};

BankAccount::BankAccount(const char *client, const char *num, double bal)
{
    strncpy(name, client, 49);      // 限制长度(截断)
    name[49] = '\0';                // 手动结束字符串   
    strncpy(accountNumber, num, 49); // 限制长度(截断)
    accountNumber[49] = '\0';        // 手动结束字符串 
    balance = bal;
}
