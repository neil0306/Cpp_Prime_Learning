#include <iostream>

int main(void)
{
    using namespace std;

    int updates = 6;
    int *p_updates;         // 创建指针, 只要 * 号前面有类型名，就是声明指针
    p_updates = &updates;   // 为指针赋值，& 取地址符, 此时, =号左右两侧都是地址

    cout << "Values: updates = " << updates << endl;        // 打印值

    cout << "p_updates = " << p_updates << endl;            // 打印地址
    cout << "Addresses: &updates = " << &updates << endl;   // 打印 update 的地址


    cout << "*p_updates = " << *p_updates << endl;          // 打印地址对应的值

    // 修改指针里的内容
    *p_updates = *p_updates + 1;                            // 修改地址对应的值: 先把地址对应的值取出来，加1，再赋值回去
    cout << "Now updates = " << updates << endl;            // 打印修改后的值

    return 0;
}