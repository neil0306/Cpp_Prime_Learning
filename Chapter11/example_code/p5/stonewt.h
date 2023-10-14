#ifndef __STONEWT_H__
#define __STONEWT_H__

#include <iostream>

using namespace std;

class Stonewt       // 描述英石
{
    public:
        enum Type{STONE, POUNDS, FLOATPOUNDS};
    private:
        enum {Lbs_per_stn = 14};        // 也可以定义为 static
        int stone;
        double pds_left;
        double pounds;
        double type;

    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();

        void Set_type(Type m);       // 用来设置显示的类型
        Stonewt operator+(const Stonewt &s) const;
        Stonewt operator-(const Stonewt &s) const;
        Stonewt operator*(double n) const;

        friend ostream & operator<<(ostream &os, const Stonewt &s); // 友元函数, 方便访问成员变量
};

#endif //!__STONEWT_H__