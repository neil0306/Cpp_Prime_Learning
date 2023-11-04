#ifndef __ARRAYTP_H__
#define __ARRAYTP_H__

#include <iostream>
using namespace std;

template <typename T, int n>
class ArrayTP
{
    private:
        T ar[n];
    public:
        T & operator[](int i);      // 可读取并修改数组内容
        T operator[](int i) const;  // 可读取数组内容, 不可修改数组

};


template <class T, int n>
T & ArrayTP<T,n>::operator[](int i)
{
    return ar[i];

}

template<class T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
    return ar[i];
}

#endif //!__ARRAYTP_H__