#include "mytimer3.h"

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

Time Time::operator*(double mult) const
{
    Time res;
    long totalMinute = hours * mult * 60 + minute * mult;
    res.hours = totalMinute / 60;
    res.minute = totalMinute % 60;
    return res;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int tol1, tol2;
    tol1 = hours * 60 + minute;
    tol2 = t.hours * 60 + t.minute;
    diff.hours = (tol1 - tol2) / 60;
    diff.minute = (tol1 - tol2) % 60;
    return diff;
}

void Time::show() const
{
    cout << "Hours = " << hours << ", Minutes = " << minute << endl;
}

// 友元函数的实现
Time operator*(double mult, const Time &t)
{
    Time res;
    long totalMinute = t.hours * mult * 60 + t.minute * mult;   // 因为是友元函数, 现在可以直接访问t里面的私有成员了
    res.hours = totalMinute / 60;
    res.minute = totalMinute % 60;
    return res;
}
