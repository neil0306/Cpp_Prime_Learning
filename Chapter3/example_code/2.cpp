#include <iostream>
#include <climits>

int main(void)
{
    using namespace std;

    short sam = SHRT_MAX;       // 有符号整型变量
    unsigned short sue = sam;   // 无符号整型变量

    cout << "Sam has " << sam << " dollors and Sue has " << sue << " dollors deposited." << endl;
    cout << "Add $1 to each account. " << endl;
    
    // 测试向上溢出
    sam = sam + 1;     // 有符号数, 原来已经是最大值, 此时会发生越界
    sue = sue + 1;      // 无符号数, 范围是 0-65535, 不会越界

    cout << "Now Sam has " << sam << " dollors and Sue has " << sue << " dollors deposited." << endl;

    // 测试向下溢出
    sam = 0;
    sue = 0;

    sam = sam - 1;
    sue = sue - 1;
    
    cout << "Now Sam has " << sam << " dollors and Sue has " << sue << " dollors deposited." << endl;

    return 0;
}