#include <iostream>
#include <cstdlib>
#include <cmath>

// #include "exc_mean.h"   // 把異常類改成C++提供的異常類
#include <stdexcept>

using namespace std;

class bad_mean : public logic_error
{
    private:
        double v1, v2;
    public:
        bad_mean(double a = 0, double b = 0, const string &what_arg = "mean, Error!") : v1(a), v2(b), logic_error(what_arg){}
        virtual void show() const;
};

// 繼承關係從 logic_error 改成 bad_mean
class bad_hmean : public bad_mean    // 公有派生自 logic_error, 注意logic_error 也是派生類, 它派生自 exception 類
{
    public:
        // 在進行成員初始化時, 調用了基類 logic_error 提供的構造函數, 此時, 這個異常類裡面的 what() 成員函數就有值了
        bad_hmean(double a = 0, double b = 0, const string & what_arg = "hmean, invalid arguments!") : bad_mean(a, b, what_arg){};
        virtual void show() const;
};

class bad_gmean : public bad_mean
{
    public:
        bad_gmean(double a = 0, double b = 0, const string & what_arg = "gmean, invalid arguments!") : bad_mean(a, b, what_arg){};
        virtual void show() const;
};

void bad_mean::show() const
{
    cout << "v1 = " << v1 << ", v2 = " << v2 << endl;
}

void bad_hmean::show() const
{
    cout << what() << endl;
    bad_mean::show();
}

void bad_gmean::show() const
{
    cout << what() << endl;
    bad_mean::show();
}

double hmean(double a, double b);
double gmean(double a, double b);

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
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            z = gmean(x,y);
            cout << "Geometric mean of " << x << " and " << y << " is " << z << endl;
        }
        // step 2: 利用處理程序捕獲異常
        // 在 hmean 中已經使用了 throw 引發異常, 這裡接著使用 catch 捕獲這個異常
        // 練習題中要求這裡只能用一個 catch 塊捕獲上面三種異常類型: 
        catch(bad_mean &b)
        {
            if(typeid(bad_hmean) == typeid(b)){
                b.show();
                break;
            }
            if(typeid(bad_gmean) == typeid(b)){
                b.show();
                break;
            }
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
        throw bad_hmean(a, b);       // 用構造函數創建了類的對象, 並作為拋出類型
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0){
        throw bad_gmean(a, b);       // 用構造函數創建了類的對象, 並作為拋出類型
    }
    return sqrt(a*b);
}
