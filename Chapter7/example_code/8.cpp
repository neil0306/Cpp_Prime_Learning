/*
讲解知识点:
    用区间范围来实现数组的访问.
    使用STL中"超尾"的概念: 数组的 end指针 指向数组[最后一个元素]的下一个元素, 即合法的访问区间是一个"左闭右开"的区间 (和python访问list是一样的逻辑)
*/
#include <iostream>

using namespace std;

const int ArSize = 8;

int sum_arr(const int *begin, const int *end); // 正规写法是 int sum_arr (int * arr, int n)

int main(void)
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sum_arr(cookies, cookies+ ArSize); // 传递一个数组给函数, 同时还传了个数

    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, cookies+3);
    cout << "First three eater are: " << sum << endl;

    sum = sum_arr(cookies+4, cookies+8);  // 计算后4个人一共吃多少
    cout << "Last four eater ate: " << sum << endl;

    return 0;
}

int sum_arr(const int *begin, const int *end)
{
    int total = 0;
    const int *pt;   // 用来匹配传入参数

    for ( pt = begin; pt < end; pt++)
    {
        total += *pt;       // 通过指针直接获得数组元素值
    }

    return total;
}


