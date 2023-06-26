#include <iostream>

using namespace std;

const int Len = 66;
const int Divs = 6;     // 最多循环6次

void subdivide(char arr[], int low, int high, int levels);

int main(void)
{
    char ruler[Len];                  // 存放竖线

    // 清空数组
    for (int i=0; i < Len; i++){
        ruler [i] = ' ';
    }

    // 给数组的前后两个位置填写一个 竖线 |
    int min = 0;
    int max = Len - 2;
    ruler[min] = ruler[max] = '|';
    ruler[Len - 1] = '\0';            // 用于结束打印
    
    cout << ruler << endl;            // 先输出一行

    for(int i = 1; i <= Divs; i++){
        subdivide(ruler, min, max, i);
        cout << ruler << endl;
    }

    return 0;
}

void subdivide(char arr[], int low, int high, int levels)
{
    if(levels == 0)
        return;

    int mid = (low + high) >> 1;
    arr[mid] = '|';

    // 左半部分
    subdivide(arr, low, mid, levels -1);

    // 右半部分
    subdivide(arr, mid, high, levels -1);
}
