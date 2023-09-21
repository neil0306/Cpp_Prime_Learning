/*
    用来定义命名空间里的结构体定义, 函数声明
*/
#include <string>

// 声明名称空间里的一个结构体, 函数的声明
namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };

    void getPerson(Person &rp);
    void showPerson(Person &rp);
}

namespace debts
{
    using namespace pers;  // 使用命名空间之后, pers里面的结构体Person, 函数等都可以直接使用
    struct Debt
    {
        Person name;
        double amount;
    };

    void getDebt(Debt &rd);
    void showDebt(const Debt &rd);
    double sumDebt(const Debt ar[], int n);
} // namespace debts
