/*
    由于本例子使用的是 C++11 之后才添加的特性, 故编译时有些编译器需要加上选项 "-std=c++11" 才能正确编译
        如 g++ 编译器就需要这个选项, 否则不能识别 initializer_list 
*/
#include <iostream>
#include <initializer_list>

using namespace std;

double sum(initializer_list<double> il);

int main(void)
{
    initializer_list<double> a({2.2, 3.3, 4.4, 5.5});           // 4 个元素
    cout << "sum = " << sum(a);
    cout << endl;

    initializer_list<double> b{1.1, 2.2, 3.3, 4.4, 5.5, 6.6};   // 6个元素
    cout << "sum = " << sum(b);
    cout << endl;

    return 0;
}

double sum(initializer_list<double> il)
{
    double total = 0.0;

    for (auto p = il.begin(); p != il.end(); p++ ){
        total += *p;
    }
    return total;
}