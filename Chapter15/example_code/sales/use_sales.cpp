#include <iostream>
#include "sales.h"

using namespace std;

int main(void)
{
    double vals1[12] = {1100, 1110, 1120, 1130, 1140, 1150, 1160, 1170, 1170, 1190, 1120, 1210};
    double vals2[12] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};

    Sales sales1(2011, vals1, 12);
    LabelSales sales2("ABC", 2012, vals2, 12);

    // ----- 測試觸發異常 (訪問數組越界的時候) ----
    try
    {
        // Show sales1
        cout << "Year = " << sales1.Year() << endl;
        for (int i = 0; i < 12; i++){
            cout << sales1[i] << " ";
            if (i % 6 == 5){    // 一行顯示6個, 然後換行
                cout << endl;
            }
        }

        // Show sales2
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label: " << sales2.Label() << endl; 
        for (int i = 0; i < 14; i++){
            cout << sales2[i] << " ";
            if (i % 6 == 5){    // 一行顯示6個, 然後換行
                cout << endl;
            }
        }
    }
    catch(LabelSales::nbad_index & bad)    // 要先寫二代派生類, 防止基類捕獲到派生類的異常!!!
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "Bad index: " << bad.bi_val() << endl;
    }   
    catch(Sales::bad_index & bad)           // bad_index 在繼承關係中屬於基類, 要寫在派生類後面
    {
        cout << bad.what() << " ";
        cout << "Bad index: " << bad.bi_val() << endl;
    }

    cout << "---------------" << endl;

    // ---- 測試異常 ---
    try
    {
        sales2[2] = 40;  // 調用可修改值的那個 operator[]() 函數
        sales1[20] = 3333;      // 越界, 這裡會觸發異常
    }
    catch(Sales::bad_index & bad)   // 新的try要寫新的 catch!
    {
        cout << bad.what() << " ";
        cout << "Bad index: " << bad.bi_val() << endl;
    }
    

    return 0;
}