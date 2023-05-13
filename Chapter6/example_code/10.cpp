#include <iostream>
using namespace std;

void showmenu(void);
void report(void);
void comfort(void);

int main(void)
{
    showmenu();
    int choice;
    cin >> choice;

    while ( choice != 5)
    {
        switch (choice)
        {
        case 1 : cout << "Warning !!!\n";
            break;
        
        case 2 : report();     // 表达式可以是一个函数
            break;

        case 3 : cout << "The boss was in all day.\n";
            break;
        
        case 4 : comfort();
            break;

        default : cout << "That's not a choice!\n";
            break;
        }
        showmenu();       // 再打印一次菜单
        cin >> choice;    // 别忘记更新跳出循环体的条件
    }

    return 0;
}

void showmenu(void)
{
    cout << "Please enter 1, 2, 3, 4, 5 as your choice: \n";
    cout << "1) alarm \t 2) report" << endl;
    cout << "3) alibi \t 4) comfort" << endl;
    cout << "5) quit \n";
}

void report(void)
{
    cout << "Sales are up 120%. expenses are down 25%.\n";
}

void comfort(void)
{
    cout << "You are the best CEO!\n";
}