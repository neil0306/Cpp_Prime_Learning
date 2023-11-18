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
    // 根據題目要求, 這裡只使用一個 catch 塊來捕獲具有繼承關係的異常類
    catch(Sales::bad_index &bad)
    {
        if(typeid(bad) == typeid(LabelSales::nbad_index)){
            LabelSales::nbad_index *p = dynamic_cast<LabelSales::nbad_index *>(&bad);
            cout << p->what();
            cout << "Company: " << p->label_val() << endl;     // 因為基類中沒有 label_val 函數(這裡是基類引用), 所以不能直接通過bad來調用
            cout << "Bad index: " << p->bi_val() << endl;
        }
        if(typeid(bad) == typeid(Sales::bad_index)){
            cout << bad.what() << " ";
            cout << "Bad index: " << bad.bi_val() << endl;
        }
    }

    cout << "---------------" << endl;

    // ---- 測試異常 ---
    try
    {
        sales2[2] = 40;  // 調用可修改值的那個 operator[]() 函數
        sales1[20] = 3333;      // 越界, 這裡會觸發異常
    }
    // 根據題目要求, 這裡只使用一個 catch 塊來捕獲具有繼承關係的異常類
    catch(Sales::bad_index &bad)
    {
        if(typeid(bad) == typeid(LabelSales::nbad_index)){
            LabelSales::nbad_index *p = dynamic_cast<LabelSales::nbad_index *>(&bad);
            cout << p->what();
            cout << "Company: " << p->label_val() << endl;     // 因為基類中沒有 label_val 函數(這裡是基類引用), 所以不能直接通過bad來調用
            cout << "Bad index: " << p->bi_val() << endl;
        }
        if(typeid(bad) == typeid(Sales::bad_index)){
            cout << bad.what() << " ";
            cout << "Bad index: " << bad.bi_val() << endl;
        }
    }
    return 0;
}