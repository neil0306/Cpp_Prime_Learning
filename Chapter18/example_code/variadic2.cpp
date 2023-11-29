#include <iostream>
#include <string>

using namespace std;

void show_list(){}      // 单独定义一个不接收参数的 show_list, 用来停止下面可变参数模板的递归调用

// 特殊修改: 为了使最后一个元素的处理更加理想, 单独对它定义一个模板函数
template <class T>
void show_list(const T &value)      // 为了效率更高, 采用引用传递
{
    cout << value << endl;
}

template<typename T, typename... Args>
void show_list(const T &value, const Args&... args)       // 注意添加引用的位置
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
    show_list(x*x, '!', 7, mr);     // 注意: 这里的x*x是一个表达式, 此时这个整体是一个"右值", 这就要求按引用传递的时候必须加const, 否则直接报错(因为按值传递需要传进去一个左值)

    return 0;
}