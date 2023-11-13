#include <iostream>
#include <cstdlib>

using namespace std;

bool hmean(double a, double b, double *ans);

int main(void)
{
    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y )
    {
        if(hmean(x, y, &z)){
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        }
        else{
            cout << "One value should not be the negative of the other, try again!" << endl;
        }
        cout << "Enter next set of numbers: ";
    }

    return 0;
}

bool hmean(double a, double b, double *ans)
{
    // 如果 a b 互為相反數就會出問題, 這裡讓函數 返回錯誤碼
    if(a == -b){
        return false;
    }
    else{
        *ans = 2.0 * a * b / (a + b);
        return true;
    }
}