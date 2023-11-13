#ifndef __EXC_MEAN_H__
#define __EXC_MEAN_H__

#include <iostream>

using namespace std;

class bad_hmean
{
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double a = 0, double b = 0) : v1(a), v2(b){}
        void mesg() const;  // 打印錯誤信息
};

inline void bad_hmean::mesg() const
{
    cout << "hmean(" << v1 << ", " << v2 << ") invalid argument: a = -b !" << endl;
}

class bad_gmean     // 乘積平方根的異常
{
    public:
        double v1;
        double v2;
    public:
        bad_gmean(double a = 0, double b = 0) : v1(a), v2(b){}  
        const char * mesg() const;
};

inline const char * bad_gmean::mesg() const
{
    return "gmean() arguments should be >= 0 !";
}

#endif //!__EXC_MEAN_H__