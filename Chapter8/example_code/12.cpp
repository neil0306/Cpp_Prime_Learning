#include <iostream>

using namespace std;

const int Lim = 8;

template <typename T>
void Swap(T &a, T &b);

void show(int arr[], int n);

template <typename T>
void Swap(T a[], T b [], int n); 

int main(void)
{
    int i = 10;
    int j = 20;
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    Swap(i,j);              // swap 接收 int 类型
    cout << "After Swap, now i,j = " << i << ", "<< j << endl;

    int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Lim] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original arrays: " << endl;
    show(d1, Lim);
    show(d2, Lim);
    Swap(d1, d2, Lim);      // 使用了重载的函数模板 
    cout << "Swapped Arrays, Now they are:" << endl;
    show(d1, Lim);
    show(d2, Lim);

    return 0;
}

// 定义一个模板函数, 来完成任意类型的参数接收. (在调用时, 编译器自动生成独立的重载函数)
template <typename T>           // 注意 <typename T> 中没有逗号也没有分号
void Swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void Swap(T a[], T b [], int n)     // 重载了函数模板, 同样使用了模板, 但是特征标不一样
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}