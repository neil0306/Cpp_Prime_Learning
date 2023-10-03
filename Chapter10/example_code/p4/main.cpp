#include "p4.h"
using namespace std;
using namespace SALES;

int main(void)
{
    double arr[4] = {11.1, 22.2, 33.3, 44.4};

    Sales s1(arr, QUARTERS);
    Sales s2;           // 使用默认构造, 这里定义为交互式的方式输入

    cout << endl;

    cout << "Now show two info: " << endl;
    s1.showSales();
    cout << "--------\n";
    s2.showSales();
    return 0;
}