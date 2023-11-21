#include <iostream>
#include <algorithm>

using namespace std;

int reduce(long arr[], int n);

int main(void)
{
    long arr[5] = {200, 100, 300, 100, 200};

    int size = reduce(arr, 5);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

int reduce(long arr[], int n)
{
    sort(arr, arr + n);     // 排序
    long *pt = unique(arr, arr + n);       // 去重, 返回末尾指针
    return pt - arr;
}