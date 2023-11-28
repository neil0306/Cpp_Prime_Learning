#ifndef __SOMEDEFS_H__
#define __SOMEDEFS_H__

#include <iostream>

using namespace std;

template <typename T, typename F>
T use_f(T v, F f)
{
    static int count = 0;       // 静态变量, 全局变量, 只初始化一次
    count++;                    // 使用一次模板函数就会加一次
    cout << "Use_f count = " << count << ", &count = " << &count << endl;
    return f(v);                // 注意, 由于是模板, f 可以是函数符, 函数指针, lambda表达式之一
}

class Fp
{
    private:
        double z_;
    public:
        Fp(double z = 1.0) : z_(z) {}
        double operator()(double p) {return z_ * p;}        // 函数符
};

class Fq
{
    private:
        double z_;
    public:
        Fq(double z = 1.0) : z_(z) {}
        double operator()(double q){return z_ + q;}         // 函数符
};


#endif  //!__SOMEDEFS_H__