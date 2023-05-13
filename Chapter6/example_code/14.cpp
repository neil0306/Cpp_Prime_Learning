#include <iostream>

using namespace std;
const int Max = 5;      // 设置最多5条鱼

int main(void)
{
    double fish[Max];
    int i = 0;

    cout << "Please enter the weight of your fish. \n";
    cout << "You may enter up to " << Max << " fish <q> to terminate." << endl;

    cout << "Fish #1: ";
    // 正确的输入有两个条件: 1. 输入的数据满足 double 能兼容的类型; 2. 输入的数据不超过 Max 条.
    while (i < Max && cin >> fish[i])  // cin 方法是有返回值的, 正确捕获的时候会返回 true, 如果发生类型不匹配, 将不会进入循环
    {
        if (++i < Max)   // i 先自增, 再与 Max 比较
            cout << "fish #" << i+1 << ": ";
    }

    double total = 0.0;
    for (int j = 0; j < i; j++)
    {
        total += fish[j];   // 如果这里不小心把 fish[j] 写成 fish[i], 由于此时的 i=5, 会发生数组越界!
    }

    cout << "total = " << total << endl;

    // 说明一下有没有捕到鱼
    if (0 == i)
        cout << "No fish! \n";
    else
        cout << "Avg weight of " << i << " fishes: " << total / i << endl;

    return 0;
}