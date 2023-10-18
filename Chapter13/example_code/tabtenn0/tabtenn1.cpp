#include "tabtenn1.h"

#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : 
                                firstname(fn), lastname(ln), hasTable(ht)
{}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    // 这里只初始化派生类 RatedPlayer 专属的数据成员
    rating = r;
}