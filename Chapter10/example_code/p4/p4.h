#ifndef __P4_H__
#define __P4_H__

#include <iostream>

namespace SALES
{
    const int QUARTERS = 4;

    class Sales
    {
        private:
            double sales[QUARTERS];
            double average;
            double max;
            double min;
        public:
            Sales();
            Sales(const double arr[], int n);
            void showSales() const;
    };
}

#endif // __P4_H__