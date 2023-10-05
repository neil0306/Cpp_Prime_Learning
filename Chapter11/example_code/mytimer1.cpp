#include "mytimer1.h"

Time::Time()
{
    hours = minute = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minute = m;
}

void Time::AddMin(int m)
{
    minute += m;                // step1: 更新分钟数
    hours += minute / 60;       // step2: 进位
    minute %= 60;               // step3: 进位后刷新分钟数.
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minute = m;
}

// Time Time::Sum(const Time &t) const
// {
//     Time sum;
//     sum.minute = minute + t.minute;
//     sum.hours = hours + t.hours;

//     // 考虑进位
//     sum.hours += sum.minute / 60;
//     sum.minute %= 60;
//     return sum;
// }

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minute = minute + t.minute;
    sum.hours = hours + t.hours;

    // 考虑进位
    sum.hours += sum.minute / 60;
    sum.minute %= 60;
    return sum;
}

void Time::show() const
{
    cout << "Hours = " << hours << ", Minutes = " << minute << endl;
}
