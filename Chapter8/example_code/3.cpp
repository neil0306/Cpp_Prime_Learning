#include <iostream>
using namespace std;

int main(void)
{
    int rat = 101;
    int & rodent = rat;
    
    cout << "rat = " << rat << endl;
    cout << "rodent = " << rodent << endl;

    int bunnies = 50;
    rodent = bunnies;       // 关联成功了吗? no!
    cout << "bunnies = " << bunnies << endl;
    cout << "rodent = " << rodent << endl;      // 发现rodent的值变成了50

    cout << "rat = " << rat << endl;  
    /* 会发现 rat 也变成了50, 这说明上面的 
        rodent = bunnies 
        并不表示 rodent 成为了 bunnies 的别名, 这句代码仅仅是赋值语句
    */

    // 观察地址
    cout << "bunnies' address:\t" << &bunnies << endl;
    cout << "rat's address:\t\t" << &rat << endl;
    cout << "rodent's address:\t" << &rodent << endl;

    return 0;
}