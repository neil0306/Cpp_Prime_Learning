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

        void show() const;
};

#endif
