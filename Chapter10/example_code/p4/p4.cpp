#include "p4.h"

using namespace std;

namespace SALES
{
    Sales::Sales(const double arr[], int n)     // n >= 4时, 只输入4个; n < 4时, 没输入的补零
    {
        double total = 0.0;
        int i = 0;

        // 赋值 & 算平均值
        for(i = 0; i < n && i < 4; i++){                   // 多于4个也还是输入4个
            sales[i] = arr[i];
            total += sales[i];
        }
        average = total / i;

        // 计算最大最小值
        max = sales[0];
        min = sales[0];
        for (int k = 1; k < i; k++){
            max = (max > sales[k]) ? max : sales[k];
            min = (min < sales[k]) ? min : sales[k];
        }

        // 异常处理
        if(n < 4){      // 输入的n不足4个, 则需要补零, 补足4个
            for(int k = n; k < 4; k++){
                sales[k] = 0;
            }
        }
    }

    Sales::Sales()
    {
        double total = 0.0;
        int i = 0;

        cout << "Enter 4 sales quarters:  " << endl;
        for (i = 0; i < QUARTERS; i++){     // 常量的声明放在头文件中.
            cout << "#" << i+1 << ": " << endl;
            cin >> sales[i];
            total += sales[i];

            if (i == 0){
                max = sales[i];
                min = sales[i];
            }
            else{
                max = (max > sales[i]) ? max : sales[i];
                min = (min < sales[i]) ? min : sales[i];
            }
        }
        average = total / QUARTERS;
    }

    void Sales::showSales() const
    {
        cout << "Sales of 4 QUARTERS: " << endl;
        for(int i = 0; i < QUARTERS; i++){
            cout << sales[i] << endl;
        }
        cout << "Average: " << average << endl;
        cout << "Max: " << max << endl;
        cout << "Min: " << min << endl;
    }
}
