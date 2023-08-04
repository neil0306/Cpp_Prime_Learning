#include <iostream>

using namespace std;

// 定义内联函数 (写法像一个宏, 但是比宏的功能更强)
inline double square(double x){return x*x;}

int main(void)
{
    double a,b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5+7.5);
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "c square = " << square(c++) << endl;
    cout << "Now c = " << c << endl;

    return 0;
}