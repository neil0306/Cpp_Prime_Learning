#include <iostream>
#include <string>

using namespace std;

void show_list(){ }      // 单独定义一个不接收参数的 show_list, 用来停止下面可变参数模板的递归调用

template<typename T, typename... Args>
void show_list(T value, Args... args)
{
    cout << value << ", ";
    show_list(args...);     // 当递归调用到最后一层时, args将不包含任何参数, 此时会调用上面定义的无参数的 show_list()
}

int main(void)
{
    int n = 14;
    double x = 2.71828;
    string mr = "Mr Rick";

    // show_list 是一个可变参数模板
    show_list(n, x);
    show_list(x*x, '!', 7, mr);

    return 0;
}