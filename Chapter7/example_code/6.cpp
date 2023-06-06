/*
讲解知识点:
    为什么传递数组的时候还顺便把数组里的元素个数也传进去?
*/
#include <iostream>

using namespace std;

const int ArSize = 8;

int sum_arr(int arr[], int n); // 正规写法是 int sum_arr (int * arr, int n)

int main(void)
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << "Cookies' address: " << cookies << endl;   // 打印数组地址   (一个判别当前系统是不是64位的小技巧, 看地址是不是超过8个数字)
    cout << "Size of cookies: " << sizeof(cookies) << endl;

    int sum = sum_arr(cookies, ArSize); // 传递一个数组给函数, 同时还传了个数

    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, 3);
    cout << "First three eater are: " << sum << endl;

    sum = sum_arr(cookies+4, 4);  // 计算后4个人一共吃多少
    cout << "Last four eater ate: " << sum << endl;

    return 0;
}

int sum_arr(int arr[], int n)
{
    int total = 0;

    cout << "Arr address: " << arr << endl;  // 打印的地址与main中的cookies地址相同, 说明函数中操作的数组就是同一个数组
    cout << "Size of Arr: " << sizeof(arr) << endl;   // 编译器会给出一个警告: 6.cpp:29:38: warning: sizeof on array function parameter will return size of 'int *' instead of 'int[]' [-Wsizeof-array-argument]
                                                    // 这个知识点是: 在函数中如果用 sizeof 去计算数组的大小, 得到的是**指针的大小**, 而不是数组的大小
                                                    // 此时我们只知道数组的开头, 并不知道数组的结尾在哪里, 所以无法计算数组的大小. 因此, 如果要用到数组的大小, 就必须把数组的大小也传进去
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    return total;
}


