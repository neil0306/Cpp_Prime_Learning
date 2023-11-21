#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

void outint(int n);

template <class T>
class TooBig
{
    private:
        T cutoff;
    public:
        TooBig(const T &t) : cutoff(t) {}
        bool operator()(const T &v){ return v > cutoff;};       // 一元谓词
};

int main(void)
{
    TooBig<int> f100(100);
    int val[10] = {50, 100, 90, 180, 60, 210, 415, 28, 188, 201};
    list<int> yadayada(val, val + 10);      // 传入迭代器
    list<int> etcetera(val, val + 10);

    cout << "Original list: " << endl;
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    cout << "Trimmed lists: " << endl;
    // 删掉 yadayada中 大于 f100.cutoff 的元素
    yadayada.remove_if(f100);     // remove_if 的参数是一个"谓词", 是一个函数符, 也就是一个类的对象(该对象有能被称为"谓词"的成员函数)
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    // 将 etcetera 里的每一个元素与 200 比较, 然后删掉大于 200 的元素
    etcetera.remove_if(TooBig<int>(200));
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    return 0;
}

void outint(int n)
{
    cout << n << " ";
}