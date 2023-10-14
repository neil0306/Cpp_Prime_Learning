#ifndef __STONEWT1_H__
#define __STONEWT1_H__

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

        void show_lbs() const;
        void show_stone() const;

        operator double() const;
        operator int() const;
};

#endif //!__STONEWT1_H__