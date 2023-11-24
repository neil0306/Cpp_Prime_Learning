#include <iostream>
#include <iomanip>  // 为了设置显示宽度必须引入

using namespace std;

int main(void)
{
    int n;
    cout << "Enter a integer: ";
    cin >> n;

    // 宽度15
    cout << showbase;       // 设置输出数字时加上进制的前缀
    cout << setw(15) << n                   // 到这里显示的是宽度15的十进制数
        << hex << setw(15) << n             // 到这里显示的是宽度15的十六进制数
        << setw(15) << oct << n << endl;    // 到这里显示的是宽度15的八进制数
    return 0;
}
