#include <iostream>

using namespace std;

class Num
{
    private:
    public:    // 为了使得 重载非成员运算符的方式能顺利访问n, 把n设置为public
        int n;
    public:
        Num();
        Num(int m);
        // Num operator+(const Num &t) const;      // 成员函数的运算符重载
        void show() const;
};

Num::Num()
{
    n = 0;
}

Num::Num(int m)
{
    n = m;
}

// 成员函数的运算符重载
// Num Num::operator+(const Num &t) const
// {
//     Num temp;
//     temp.n = n + t.n;
//     return temp;
// }


// 非成员运算符的重载方式
Num operator+(const Num &m, const Num &l)
{
    Num temp;
    temp.n = m.n + l.n;     // 要注意 n 是否为 Num 里的公有变量
    return temp;
}


void Num::show() const
{
    cout << "n = " << n << endl;
}

int main(void)
{
    Num a(10);
    a.show();

    Num b(20);
    b.show();

    // 测试成员函数 & 非成员函数的运算符重载方式
    Num c = a + b;
    c.show();

    return 0;
}