#include <iostream>
using namespace std;

class Num
{
    private:
        int n;
    public:
        Num();
        Num(int m);
        void operator=(int l);      // 重载赋值运算符
};

Num::Num()
{
    n = 0;
    cout << "Hello World!" << endl;
}

Num::Num(int m)
{
    n = m;
    cout << "Good Morning." << endl;
}

void Num::operator=(int l)
{
    n = l;
    cout << "I love you Rick." << endl;
}

int main(void)
{
    Num a;

    //////// 测试没有进行赋值运算符重载的情况(需要注释掉上面的 operater+(int l) ) ////////
    /// 触发自定义构造函数 Num::Num(int m)
    ///   这是因为 "当一个类的声明中没有重载赋值运算符(=)时, 编译器会自动调用与右侧变量具有相同类型的类的构造函数", 此时的赋值运算符的具体功能是由编译器提供的, 本质上是编译器提供了一个默认的运算符重载.
    ///   即: 在 Num 中我们没有重载 = 号, 而下面的赋值语句右侧是10, 是int类型, 恰好构造函数 Num(int m) 的输入参数是int类型, 于是直接调用了它.
    // a = 10;     // 此语句等价于 a(10)

    //////// 测试重载后的赋值运算符 /////////
    a = 10;
    return 0;
}
