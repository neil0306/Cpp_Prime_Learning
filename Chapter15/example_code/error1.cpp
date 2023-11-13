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
        z = hmean(x,y);
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers: ";
    }

    return 0;
}

double hmean(double a, double b)
{
    // 如果 a b 互為相反數就會出問題, 這裡採用直接終止程序的方式
    if(a == -b){
        cout << "Invalid arguments to hmean()" << endl;
        abort();        // 加了這個函數之後, 如果運行時進入這個代碼段, 程序就會直接終止
    }
    return 2.0 * a * b / (a + b);
}