#include <iostream>

using namespace std;

void cheers(int n);
double cube(double x);

int main(void)
{
    
    cheers(5);

    double side;

    cout << "Give me a number: ";
    cin >> side;
    double volume = cube(side);  // 声明连带着赋值 + 函数调用

    cout << side << " cube = " << volume << endl;

    cheers(cube(2));  // 注意发生了隐式类型转换, 2被转换成了double类型, 返回值又转到int

    return 0;
}

void cheers(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Cheers! ";
    }
    cout << endl;
}

double cube(double x)
{
    return x*x*x;
}
