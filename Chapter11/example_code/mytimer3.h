#ifndef __MYTIMER0_H__
#define __MYTIMER0_H__

#include <iostream>

using namespace std;

class Time
{
    private:
        int hours;
        int minute;

    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);

        Time operator+(const Time &t) const;
        Time operator-(const Time &t) const;
        Time operator*(double mult) const;

        // 声明友元函数
        friend Time operator*(double mult, const Time &t);

        void show() const;
};

// Time operator*(double m, const Time &t);  定义了友元函数, 这里就不需要声明了

#endif
