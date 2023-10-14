#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    stone = static_cast<int>(lbs) / Lbs_per_stn;  // 强制类型转换也可以写为 (int)lbs
    pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;  // 整数部分 + 小数部分
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds." << endl;
}

void Stonewt::show_stone() const 
{
    cout << stone << " stone, " << pds_left << " pounds." << endl;
}

Stonewt Stonewt::operator*(double mult)
{
    return Stonewt(pounds * mult);
}
