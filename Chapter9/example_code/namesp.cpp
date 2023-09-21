/*
    用来写名称空间中函数的具体定义
*/
#include <iostream>
#include "namesp.h"

namespace pers
{
    // using 声明
    using std::cout;
    using std::cin;

    void getPerson(Person &rp)     // 函数声明放在头文件中, 声明同样放在命名空间内部
    {
        cout << "Enter first name: ";
        cin >> rp.fname;
        cout << "Enter last name: ";
        cin >> rp.lname;
    }

    void showPerson(const Person &rp)
    {
        cout << rp.lname << ", " << rp.fname;
    }
}

namespace debts
{
    void getDebt(Debt &rd)          // Debt 结构体定义在头文件中, 在debts命名空间内
    {
        // 填入数据
        getPerson(rd.name);         // getPerson 是名称空间 pers 里面定义的函数, 用来输入信息
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }

    void showDebt(const Debt &rd)
    {
        // 输出数据
        showPerson(rd.name);        // showPerson 是名称空间 pers 里面定义的函数, 用来显示信息
        std::cout << ": $" << rd.amount << std::endl;
    }

    double sumDebt(const Debt ar[], int n)
    {
        double total = 0.0;
        for(int i = 0; i < n; i++)
        {
            total += ar[i].amount;
        }
        return total;
    }
}
