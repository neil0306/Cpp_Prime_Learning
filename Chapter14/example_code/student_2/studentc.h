#ifndef __STUDENTC_H__
#define __STUDENTC_H__

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student : private string, private valarray<double>    // 私有继承了两个类 (多重继承, multiple inheritance, MI)
{
    private:
        typedef valarray<double> ArrayDb;       // 使用别名, 方便简写, 此时只能在类内部使用这个别名
        ostream & arr_out(ostream &os) const;      // 用来替代非私有继承时写过的输出运算符重载函数

    public:
        Student() : string("Null Student"), ArrayDb(){}

        // 转换函数(同时也是构造函数): string类型 转换为 Student类型
        explicit Student(const string &s) : string(s), ArrayDb(){}      // 注意是显式转换(此时不允许隐式转换), 加了关键字 explicit
        explicit Student(int n) : string("Nully"), ArrayDb(n){}         // 这里也是不允许隐式转换
        
        Student(const string &s, int n) : string(s), ArrayDb(n){}
        Student(const string &s, const ArrayDb &a ) : string(s), ArrayDb(a){}      // score 部分对应的是 valarray(valarray对象) 的使用方式
        Student(const string &s, const double *pd, int n) : string(s), ArrayDb(pd, n){}  // score 部分对应的是 valarray(double数组, 数组长度) 的使用方式

        ~Student(){}

        double Average() const;
        const string & Name() const;
        double & operator[](int n);   // 注意返回的是引用类型, 返回的是"左值"(可写/修改), 此时才可以写成 stu[0] = 100, 此时的 stu[0] 是可读可写的
        double operator[](int n) const;  // 如果把返回值写"非引用"的形式, 那么调用[]运算符得到的对象是"右值", 它是"只读"的, 合法的使用只能是 a = stu[0], 因为 stu[0] 是右值(只读, 不可修改)

        friend istream & operator>>(istream &is, Student &stu); // 用于捕获输入时中间有空格的情况
        friend istream & getline(istream &is, Student &stu);    // 重载捕获一整行的输入情况
        friend ostream & operator<<(ostream &os, const Student &stu);

    public:
        // 使友元函数能调用 私有基类方法 的 "解决方案2": 用 using 声明
        using valarray<double>::size;
        using valarray<double>::operator[];
};

#endif //!__STUDENTC_H__
