#ifndef __COMPLEX0_H__
#define __COMPLEX0_H__
#include <iostream>

using namespace std;

class complex
{
    private:
        double real;
        double imaginary;
    public:
        complex();
        complex(double r, double i);
        complex operator+(const complex &c) const;
        complex operator-(const complex &c) const;
        complex operator*(const complex &c) const;
        complex operator~() const;      // 共轭 (conjugate)

    public:
        friend complex operator*(double x, const complex &c);     // 友元函数实现乘法交换律
        friend istream & operator>>(istream &is, complex &c);     // 输入是需要修改 complex对象的, 所以不要加const
        friend ostream & operator<<(ostream &os, const complex &c);

};

#endif //!__COMPLEX0_H__