#include <iostream>

using namespace std;


// 对于下面的联合体, 它有两个成员变量 ch 和n, 占用的空间为最大的成员变量的空间, 也就是4个byte, 
//  如果是结构体的话就是所有成员变量的空间之和, 为5个byte
union one2all           // 使用 union 关键字
{
    char ch;            // 成员变量也是语句, 不要漏了分号
    int n;
};                      // 这是一个语句, 不要漏了分号

int main(void)
{
    one2all num;
    cout << "Sizeof(num): " << sizeof(num) << endl; // 输出4

    cout << "现在给 num 的 ch 成员进行赋值\n";
    num.ch = 'A';           // 激活了 ch 成员
    cout << "num.ch: " << num.ch << endl;       // 输出 A
    cout << "num.n: " << num.n << endl;         // 输出随机数 (说明了 ch 和 n 共用了同一块内存, 但是ch只占用了一个byte, 还有3个byte没有初始化, 所以n的值看上去是随机的)

    cout << "\n\n现在给 num 的 n 成员进行赋值\n";
    num.n = 97;           // 激活了 ch 成员
    cout << "num.n: " << num.n << endl;         // 输出97
    cout << "num.ch: " << num.ch << endl;       // 输出 a, (说明了 ch 和 n 共用了同一块内存, n占用了4个 byte, 把整块内存用完了, 所以 ch 直接读取了 n 的值, 也就是97, 97对应的ASCII码就是a)

    return 0;
}