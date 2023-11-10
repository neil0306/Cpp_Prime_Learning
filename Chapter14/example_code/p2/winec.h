#ifndef __WINEC_H__
#define __WINEC_H__

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

template <class T1, class T2> class Pair;       // 声明一下, 为了让 typedef 能识别 Pair
typedef valarray<int> ArrInt;
typedef Pair< ArrInt, ArrInt > PairArray;

// Pair模板类
template <class T1, class T2>
class Pair
{
    private:
        T1 a;
        T2 b;
    public:
        Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval){}
        T1 & first();
        T2 & second();
        T1 first() const{return a;}
        T2 second() const{return b;}
};

template <class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

// 酒 类
class Wine : private string, private PairArray
{
    private:
        // string label;            // 私有继承之后, 将自动获得一个匿名的 string 对象, 因此这里可以不写label了
        // PairArray info;          // 同理, 可以不写info了, 它是一个匿名的 PairArray 对象
        int year;
    public:
        Wine(const char *l, int y, const int yr[], const int bot[]);
        Wine(const char *l, int y);
        void GetBottles();      // 用于录入信息
        const string & Label() const;
        int sum() const;
        void Show() const;
};

#endif //!__WINEC_H__