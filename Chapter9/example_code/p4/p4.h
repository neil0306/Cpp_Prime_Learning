#ifndef __P4_H__
#define __P4_H__

#include <iostream>

namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    void setSales(Sales &s, const double arr[], int n);      // n >= 4时, 只输入4个; n < 4时, 没输入的补零
    void setSales(Sales &s);
    void showSales(const Sales &s);

}

#endif // __P4_H__