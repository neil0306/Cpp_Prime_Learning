#include <iostream>

using namespace std;

int main(void)
{
    int a,b;
    int c;

    cout << "enter two integers: ";
    cin >> a >> b;   // 连续读取, 并放入对应的变量中

    c = a > b ? a : b;  // 如果 a>b, 返回a; 否则返回b

    /*
    等效为:
    if (a > b)
        c = a;
    else
        c = b
    */

    cout << "The larger of "<< a << " and " << b << " is " << c << endl;
    return 0;
}