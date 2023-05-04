
#include <iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    int x = 20;

    for (int i = 0; i < 3; i++)
    {
        cout << "In For-loop(before init x): x = " << x << endl;    // 此时打印的是 for 外面的 x, 20
        
        int x = 100;                                                // 声明了一个 for 外面的同名变量

        cout << "In For-loop: x = " << x << endl;                   // 打印 100
        
        int y = 200;        // 在循环体里定义一个变量, 循环体外侧无法访问
    }
    cout << "After For-loop end, x = " << x << endl;                // 此时打印的是 for 外面的 x, 20

    // cout << "y = " << y << endl;                                    // 此时 y 不存在, 编译就报错了
    
    return 0;
}