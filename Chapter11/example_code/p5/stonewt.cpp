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

void Stonewt::Set_type(Type m)
{
    type = m;
}

Stonewt Stonewt::operator+(const Stonewt &s) const
{
    return Stonewt(pounds + s.pounds);
}

Stonewt Stonewt::operator-(const Stonewt &s) const
{
    return Stonewt(pounds - s.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds * n);
}

ostream & operator<<(ostream &os, const Stonewt &s)
{
    if(s.type == Stonewt::STONE){
        os << s.stone << " stone, " << s.pds_left << " pounds.\n";
    }
    else if (s.type == Stonewt::POUNDS){
        os << static_cast<int>(s.pounds) << " pounds.\n";       // 输出磅数(int类型)
    }
    else if(s.type == Stonewt::FLOATPOUNDS){
        os << s.pounds << " pounds.\n";
    }
    else{
        os << "Invalid type!\n";
    }
    return os;
}
