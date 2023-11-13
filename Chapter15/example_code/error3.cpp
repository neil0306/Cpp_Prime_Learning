#include <iostream>
#include <cstdlib>

using namespace std;

double hmean(double a, double b);

int main(void)
{
    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y )
    {
        // step 3: 使用 try 模塊包住可能有異常的代碼 (throw語句包含在這裡面)
        try{
            // 容易出現異常的代碼通常放在 try 裡的代碼塊
            z = hmean(x,y);
        }
        // step 2: 利用處理程序捕獲異常
        // 在 hmean 中已經使用了 throw 引發異常, 這裡接著使用 catch 捕獲這個異常
        catch(const char *s)       // 處理字符串的異常, 此時 s 中存放的是 throw 拋出來的字符串賦值
        {
            cout << s << endl;
            cout << "Enter a new pair of arguments." << endl;
            continue;
        }

        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers: ";
    }

    return 0;
}

double hmean(double a, double b)
{
    // 如果 a b 互為相反數就會出問題, 這裡使用 throw 引發異常, 並且是 "字符串類型的異常(const char *)"
    if(a == -b){
        // step 1: 在可能引發異常的代碼中增加 throw 語句以拋出異常
        throw "Bad hmean() arguments, a=-b is not allowed!";        // throw 後可以加字符串 或者 C++的類型(包括類類型), 它會終止函數的運行(程序還會繼續走)
    }
    return 2.0 * a * b / (a + b);
}