#include "dma.h"

using namespace std;

int main(void)
{
    // 测试基类
    baseDMA shirt("Protabelly", 8);
    cout << "Displaying baseDMA object: " << endl;
    cout << shirt;
    cout << "-----------------" << endl;

    // 测试不用new的派生类
    lacksDMA ballon("Blimpo", 4, "red");
    cout << "Displaying lacksDMA object: " << endl;
    cout << ballon;
    cout << "-----------------" << endl;

    lacksDMA ballon2(ballon);       // 调用复制构造(基类自定义的复制构造+派生类的默认复制构造)
    cout << "Result of lacksDMA object: " << endl;
    cout << ballon2;                // 从显示结果看, 基类和派生类的数据都成功拷贝到了 ballon2
    cout << "-----------------" << endl;

    // 测试使用new的派生类
    hasDMA map("Keys", 5, "Mercator");
    cout << "Displaying hasDMA object: " << endl;
    cout << map;
    cout << "-----------------" << endl;

    hasDMA map2 = map;              // 这是初始化, 触发 复制构造函数 (从输出可以看到)
    map2 = map;                     // 这里是调用赋值运算符
    cout << "Result of hasDMA copy: " << endl;
    cout << map2;
}