/*
    代碼例子: 演示 unwinding the stack (棧解退)
*/
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "exc_mean.h"

using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);
double mean(double a, double b);

int main(void)
{
    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y )
    {
        // step 3: 使用 try 模塊包住可能有異常的代碼 (throw語句包含在這裡面)
        try{
            // 注意 mean 中也包含了 try代碼塊
            z = mean(x,y);
            cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
        }
        // step 2: 利用處理程序捕獲異常
        // 由於 mean 中存在 try代碼塊 和 catch部分, 如果 mean 中沒有繼續用 throw 再次拋出異常, 則到這裡的 catch 將不會被執行 
        catch(const char *s)
        {
            cout << s << endl;
            cout << "Enter a new pair of arguments." << endl;
            continue;
        }
        catch(bad_hmean &bh) 
        {
            bh.mesg();              // 內部帶輸出語句
            cout << "2) exception." << endl;          // 捕抓 mean 再次拋出的異常
            cout << "Enter a new pair of arguments." << endl;
            continue;
        }
        catch(bad_gmean &gh)        // bh 會接收 throw 過來的類的對象
        {
            cout << gh.mesg() << endl;      // bad_gmean 裡的 mesg 返回了一個字符串
            cout << "Value used: " << gh.v1 << ", " << gh.v2 << endl;
            cout << "Sorry, quit now." << endl;
            break;
        }
        cout << "Enter next set of numbers: ";
    }

    return 0;
}

double hmean(double a, double b)
{
    // 如果 a b 互為相反數就會出問題, 這裡使用 throw 引發異常, 並且是 "字符串類型的異常(const char *)"
    if(a == -b){
        // step 1: 在可能引發異常的代碼中增加 throw 語句以拋出異常
        throw bad_hmean(a,b);       // 用構造函數創建了類的對象, 並作為拋出類型
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0){
        throw bad_gmean(a,b);       // 用構造函數創建了類的對象, 並作為拋出類型
    }
    return sqrt(a*b);
}

// mean函數不包含任何拋出異常的語句, 能引發異常的函數只有 hmean 和 gmean
double mean(double a, double b)
{
    double am, hm, gm;      // am 是算術平均數 (a+b)/2
    am = (a + b) / 2.0;

    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch(bad_hmean &bh)
    {
        bh.mesg();
        cout << "1) exception" << endl;

        // 為了能讓 main 函數的 try-catch 能捕獲到異常, 這裡再拋一次.
        throw;          // 如果什麼都不寫, 則表示拋出這裡相同類型的異常, 也就是 "bad_hmean &" 類型
    }
    cout << "Hello World." << endl;     // 如果這裡的 try-catch 沒有再次拋出異常的話, 這句 Hello World 將會被執行, 而如果這裡拋出了異常, 則直接跳到 main 函數, 這行代碼不會被執行

    return (am + hm + gm) / 3.0;
}
