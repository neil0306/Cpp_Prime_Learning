#include "vector.h"
#include <cmath>

namespace VECTOR
{
    const double Rad_to_deg = 45 / atan(1.0);    // 弧度转角度: 1弧度转化为多少角度

    Vector::Vector()   // 构造函数
    {
        x = y = ang = mag = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;      // 这里弧度制转了角度制
            set_x();
            set_y();
        }
        else{
            cout << "Construction Error!!!" << endl;
            // 恢复默认值
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }

    void Vector::set_mag()
    {
        mag  = sqrt(x*x + y*y);
    }

    void Vector::set_ang()
    {
        if(x == 0.0 && y == 0.0){
            ang = 0.0;
        }
        else{
            ang = atan2(y,x);  // API返回的是[弧度制]的角度
        }
    }

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;      // 这里弧度制转了角度制
            set_x();
            set_y();
        }
        else{
            cout << "Reset Error!!!" << endl;
            // 恢复默认值
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector &b) const
    { 
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-() const        // 取反
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x-b.x, y-b.y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(x*n, y*n);
    }

    Vector operator*(double n, const Vector &a)
    {
        // return Vector(n*a.x, n*a.y);
        return a * n;       // 偷懒写法: 使用上面重载的乘法, 注意是a的成员函数
    }

    ostream & operator<<(ostream &os, const Vector &v)
    {
        if(v.mode == Vector::RECT)     // POL 是 Vector类 里定义的枚举量, 并且在public里
        {
            os << "x, y = " << v.x << ", " << v.y << endl;
        }
        else if(v.mode == Vector::POL)
        {
            os << "mag, ang = " << v.mag << ", " << v.ang << endl;
        }
        else{
            os << "Invalid mode!" << endl; 
        }
        return os;
    }
}
