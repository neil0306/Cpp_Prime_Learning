#include <iostream>

int main(void)
{
    using namespace std;

    int x;
    cout << "The expression x =100 has the value ";
    
    // cout << x = 100 << endl;  // 报错, 编译的时候, 编译器会因为运算符优先级问题而无法识别 "x左右两侧的运算符" 的含义
    //                             // 由于 "<<" 的优先级比"=" 高, 
    //                             // 因此编译器优先执行 "cout << x", 把x直接输出.
    //                             // 然后编译器开始解读 " = 100 << endl;", 解析不了, 就报错了
    
    cout << (x = 100) << endl;   // value 打印出来是100

    cout << "now x = " << x << endl;

    cout << (x < 3) << endl;   // value 打印出来是0, 表示 false
    
    cout << (x > 3) << endl;   // value 打印出来是1, 表示 true

    cout.setf(ios_base::boolalpha);     // 把 true false原样显示, 而不是打印数字
    cout << (x < 3) << endl;   // value 打印出来是 false
    cout << (x > 3) << endl;   // value 打印出来是 true

    return 0;
}