#include "p4.h"
using namespace std;
using namespace SALES;

int main(void)
{
    double arr[4] = {11.1, 22.2, 33.3, 44.4};
    Sales sl;
    setSales(sl, arr, 4);
    showSales(sl);

    setSales(sl);       // 交互式函数, 重载函数
    showSales(sl);
    return 0;
}