#ifndef __GOLF_H__
#define __GOLF_H__

#include <iostream>
#include <cstring>

using namespace std;

const int Len = 40;

/*
struct golf
{
    char fullname[Len];
    int handicap;
};

void setgolf(golf & g, const char * name, int hc);

int setgolf(golf & g);

void handicap(golf & g, int hc);

void showgolf(const golf &g);
*/

// 改用类来实现 golf
class golf
{
    private:
        char fullname[Len];
        int handicap;

    public:
        golf();     // 改写 int setgolf(golf & g);
        golf(const char * name, int hc);  // 改写 void setgolf(golf & g, const char * name, int hc);
        void setHandicap(int hc);
        void showgolf() const;
};

#endif
