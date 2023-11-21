#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

template <class T>
int reduce(T arr[], int n);

int main(void)
{
    long arr[5] = {200, 100, 300, 100, 200};

    int size = reduce(arr, 5);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    string str[5] = {"hello", "world", "good", "morning", "world"};
    size = reduce(str, 5);
    for(int i = 0; i < size; i++){
        cout << str[i] << " ";
    }
    cout << endl;
    return 0;
}

template <class T>
int reduce(T arr[], int n)
{
    list <T> ls;
    for (int i = 0; i < n; i++){
        ls.push_back(arr[i]);           // 元素放入链表
    }

    ls.sort();
    ls.unique();

    auto pt = ls.begin();               // 取出迭代器, 类型交给编译器判断
    for(int i = 0; i < ls.size(); i++, pt++){
        arr[i] = *pt;                   // 获取元素, 重新填充到 arr 中(覆盖写)
    }

    return ls.size();
}