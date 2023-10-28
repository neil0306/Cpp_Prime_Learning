#ifndef __STUDENTC_H__
#define __STUDENTC_H__

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class student
{
    private:
        typedef valarray<double> ArrayDb;       // 使用别名, 方便简写, 此时只能在类内部使用这个别名
        string name;
        ArrayDb scores;         // 等价于 valarray<double> scores;
    public:
        
};

#endif //!__STUDENTC_H__