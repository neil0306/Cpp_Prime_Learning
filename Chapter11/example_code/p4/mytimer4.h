#ifndef __MYTIMER4_H__
#define __MYTIMER4_H__

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

        // Time operator+(const Time &t) const;
        // Time operator-(const Time &t) const;
        // Time operator*(double mult) const;

        // 运算符重载改成友元函数
        friend Time operator +(const Time &s, const Time &t);
        friend Time operator -(const Time &s, const Time &t);
        friend Time operator *(const Time &s, double mult);
        friend Time operator*(double mult, const Time &t);

        // void show() const;

        friend ostream & operator<< (ostream &os, const Time &t);     // 声明友元函数重载
};

// Time operator*(double m, const Time &t);  定义了友元函数, 这里就不需要声明了

#endif
