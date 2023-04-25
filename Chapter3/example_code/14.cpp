#include <iostream>
using namespace std;

int main(void)
{
    int auks, bats, coots;

    auks = 19.99 + 11.99;               // 小数被舍弃
    bats = (int) 19.99 + (int)11.99;    // 先强制类型转换
    coots = int(19.99) + int(11.99);    // 先强制类型转换

    cout << "auks = " << auks << endl;  // 输出31
    cout << "bats = " << bats << endl;  // 输出30 
    cout << "coots = " << coots << endl; // 输出30

    char ch = 'Z';
    cout << "The code for " << ch << " is " << int(ch) << endl;
    
    cout << "The code for " << ch << " is " 
         << static_cast<int>(ch) << endl;     // 使用高级点的

    return 0;
}