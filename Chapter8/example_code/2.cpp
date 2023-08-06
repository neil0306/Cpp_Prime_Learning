#include <iostream>
using namespace std;

int main(void)
{
    int rat = 10;
    int & rodent = rat;
    
    cout << "rat = " << rat << endl;
    cout << "rodent = " << rodent << endl;

    // 改变rodent
    rodent ++;
    cout << "rat = " << rat << endl;
    cout << "rodent = " << rodent << endl;

    // 观察地址
    cout << "rat's address: " << &rat << endl;
    cout << "rodent's address: " << &rodent << endl;

    return 0;
}