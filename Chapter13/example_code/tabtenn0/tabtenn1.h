#ifndef __TABTENN0_H__
#define __TABTENN0_H__

#include <iostream>
#include <string>

using std::string;

class TableTennisPlayer
{
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const string &fn = "none",
                            const string &ln = "noen", bool ht = false);
        void Name() const;
        bool HasTable() const {return hasTable;}
        void ResetTable(bool v) {hasTable = v;}
};

class RatedPlayer : public TableTennisPlayer        // 派生出RatedPlayer, public表示这是公有派生
{
    private:
        unsigned int rating;
    public:
        RatedPlayer(unsigned int r = 0, const string &fn = "none", const string &ln = "none", bool ht = false);
        RatedPlayer(unsigned int r, const TableTennisPlayer &tp);       // 此时直接传了一个基类的对象作为参数
        unsigned int Rating() const {return rating;}
        void ResetRating(unsigned int r) {rating = r;}
};

#endif //!__TABTENN0_H__
