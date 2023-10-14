#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

using namespace std;

namespace VECTOR
{
    class Vector 
    {
        public:
            enum Mode{RECT, POL};   // 直角坐标, 极坐标

        private:
            double x;
            double y;
            Mode mode;      // 相当于一个标志位的作用, 但它是枚举类型
            void set_x(double mag, double ang);     // 删除了原来的mag和ang成员变量, 这里就需要直接提供
            void set_y(double mag, double ang);
        
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);

            // xval, yval(), magval(), angval() 在这里定义, 编译时会自动变成内联函数
            double xval() const
            {
                return x;
            }
            double yval() const
            {
                return y;
            }
            double magval() const;
            double angval() const;

            void polar_mode();
            void rect_mode();

            Vector operator+(const Vector &b) const;    // 重载加法: 做加法
            Vector operator-(const Vector &b) const;    // 重载减法: 做减法
            Vector operator-() const;                   // 重载减法: 取负值
            Vector operator*(double n) const;           // 放大一定倍数

            friend Vector operator*(double n, const Vector &a); // 友元函数, 实现乘法的交换律
            friend ostream & operator<<(ostream &os, const Vector &v);      // 显示函数
    };

}       // 注意不用写分号

#endif //!__VECTOR_H__