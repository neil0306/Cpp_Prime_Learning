#include <iostream>

int main(void)
{
    using namespace std;

    // int i;     // 如果在这里声明 i, 则执行完for语句之后, i 仍然可用
    for( int i = 0; i<5; i++)
    {
        cout << "C++ knows loop" << endl;
    }

    // cout << "i = " << i << endl;   // 编译不通过, 此时的 i 已经不可见了

    cout << "C++ knows when to stop." << endl;
    
    return 0;
}