#include <iostream>

using namespace std;

// 考虑一个参数都没有的时候(递归的终止条件)
long double sum_value(){ return 0.0; }

template <class T, class ... Args>
long double sum_value(const T & value, const Args & ...args)
{
    long double total;
    total = (long double)value + sum_value(args...);         // 解包, 注意value的类型不确定, 所以需要加一个强制类型转换
    return total;
}

int main(void)
{
    cout << sum_value(1, 2, 3, 4, 5) << endl;
    cout << sum_value('a', 'b', 2.2, 3.3, 5, 6, 7) << endl;
    return 0;
}