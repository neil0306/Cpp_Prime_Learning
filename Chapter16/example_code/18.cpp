/*
    测试 remove() 
*/
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

const int LIM = 10;

void Show(int n);

int main(void)
{
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};

    list<int> la(ar, ar + 10);
    list<int> lb(ar, ar + 10);

    cout << "Original list: " << endl;
    cout << "la: ";
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    cout << "lb: ";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;

    // 通过对象使用 remove: 不仅删除元素, 还对列表的大小做了改变
    la.remove(4);       // 删除所有为4的元素
    cout << "After remove(4) method: " << endl;
    cout << "la: ";
    for_each(la.begin(), la.end(), Show);
    cout << endl;

    // 使用 STL 的 remove(): 只删除对应元素, 但是不改变原来列表的大小, 由于删除而多出来的几个位置将填入无法确定的数值(这段内存地址本来存了什么值就直接拿出来塞进去了)
    list<int>::iterator last;                       //存储 remove 返回的超尾迭代器
    last = remove(lb.begin(), lb.end(), 4);         // remove会返回一个 "超尾" 迭代器
    cout << "After remove() function: " << endl;
    cout << "lb: ";
    for_each(lb.begin(), lb.end(), Show);           // 从输出结果可以看到, remove() 输出还是10个元素, 虽然已经删除了4, 但是输出结果的时候, 它不仅输出了删除4之后的结果, 为了保持原来的列表长度会多输出几个数, 但多出来的元素的值就不确定了
    cout << endl;

    // 为了保证使用 remove() 之后能改变容器的大小, 应该配合使用 .erase() 方法
    lb.erase(last, lb.end());
    cout << "After erase() method: " << endl;
    cout << "lb: ";
    for_each(lb.begin(), lb.end(), Show);           // 此时就把多余的元素清掉了
    cout << endl;

    return 0;
}

void Show(int n)
{
    cout << n << " ";
}