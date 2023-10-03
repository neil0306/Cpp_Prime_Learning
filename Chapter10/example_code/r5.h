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
