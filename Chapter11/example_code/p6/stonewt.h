#ifndef __STONEWT_H__
#define __STONEWT_H__

#include <iostream>

using namespace std;

class Stonewt       // 描述英石
{
    private:
        enum {Lbs_per_stn = 14};        // 也可以定义为 static
        int stone;
        double pds_left;
        double pounds;

    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();

        // 重载6个关系运算符
        bool operator<(const Stonewt &s) const;
        bool operator<=(const Stonewt &s) const;
        bool operator>(const Stonewt &s) const;
        bool operator>=(const Stonewt &s) const;
        bool operator==(const Stonewt &s) const;
        bool operator!=(const Stonewt &s) const;


        void show_lbs() const;
        void show_stone() const;
};

#endif //!__STONEWT_H__