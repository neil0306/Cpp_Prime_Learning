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

// 使用成员初始化列表初始化所有的成员变量
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp), rating(r)        // 触发基类的复制构造函数, 如果没有自定义, 就会使用默认复制构造
{}