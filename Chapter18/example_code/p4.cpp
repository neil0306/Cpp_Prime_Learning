#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
    auto OutInt = [](int n){cout << n << " ";};             // 有名的lambda表达式

    int val[10] = {50, 100, 90, 180, 60, 210, 415, 28, 188, 201};
    list<int> yadayada(val, val + 10);      // 传入迭代器
    list<int> etcetera(val, val + 10);

    cout << "Original list: " << endl;
    for_each(yadayada.begin(), yadayada.end(), OutInt);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), OutInt);
    cout << endl;

    cout << "Trimmed lists: " << endl;
    // 删掉 yadayada中 大于 f100.cutoff 的元素
    yadayada.remove_if([](int n){return n > 100;});         // 换成lambda表达式
    for_each(yadayada.begin(), yadayada.end(), OutInt);
    cout << endl;

    // 将 etcetera 里的每一个元素与 200 比较, 然后删掉大于 200 的元素
    etcetera.remove_if([](int v){return v > 200;});         // 换成lambda表达式
    for_each(etcetera.begin(), etcetera.end(), OutInt);
    cout << endl;
    return 0;
}
