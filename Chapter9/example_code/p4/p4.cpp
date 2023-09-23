#include "p4.h"

using namespace std;

namespace SALES
{
    /// @brief 非交互式填充结构体内容
    /// @param s 
    /// @param arr 
    /// @param n 
    void setSales(Sales &s, const double arr[], int n)     // n >= 4时, 只输入4个; n < 4时, 没输入的补零
    {
        double total = 0.0;
        int i = 0;

        // 赋值 & 算平均值
        for(i = 0; i < n && i < 4; i++){                   // 多于4个也还是输入4个
            s.sales[i] = arr[i];
            total += s.sales[i];
        }
        s.average = total / i;

        // 计算最大最小值
        s.max = s.sales[0];
        s.min = s.sales[0];
        for (int k = 1; k < i; k++){
            s.max = (s.max > s.sales[k]) ? s.max : s.sales[k];
            s.min = (s.min < s.sales[k]) ? s.min : s.sales[k];
        }

        // 异常处理
        if(n < 4){      // 输入的n不足4个, 则需要补零, 补足4个
            for(int k = n; k < 4; k++){
                s.sales[k] = 0;
            }
        }
    }

    /// @brief 交互式的方式填充结构体内容
    /// @param s 
    void setSales(Sales &s)
    {
        double total = 0.0;
        int i = 0;

        cout << "Enter 4 sales quarters:  " << endl;
        for (i = 0; i < QUARTERS; i++){     // 常量的声明放在头文件中.
            cout << "#" << i+1 << ": " << endl;
            cin >> s.sales[i];
            total += s.sales[i];

            if (i == 0){
                s.max = s.sales[i];
                s.min = s.sales[i];
            }
            else{
                s.max = (s.max > s.sales[i]) ? s.max : s.sales[i];
                s.min = (s.min < s.sales[i]) ? s.min : s.sales[i];
            }
        }
        s.average = total / QUARTERS;
    }

    void showSales(const Sales &s)
    {
        cout << "Sales of 4 QUARTERS: " << endl;
        for(int i = 0; i < QUARTERS; i++){
            cout << s.sales[i] << endl;
        }
        cout << "Average: " << s.average << endl;
        cout << "Max: " << s.max << endl;
        cout << "Min: " << s.min << endl;
    }
}
