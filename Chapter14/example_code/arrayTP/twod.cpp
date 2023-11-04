#include "arraytp.h"
#include <iostream>

using namespace std;

int main(void)
{
    ArrayTP<int, 10> sums;                      // 存放数组每行元素的和
    ArrayTP<double, 10> aves;                   // 每行元素的平均值
    ArrayTP<ArrayTP<int, 5>, 10> twodee;        // 二维数组: 10行5列

    int i,j;
    for (i = 0; i < 10; i++){
        sums[i] = 0;
        for (j = 0; j < 5; j++){
            twodee[i][j] = (i + 1) * (j+1);     // 给二维数组赋值
            sums[i] += twodee[i][j];            // 元素求和
        }
        aves[i] = (double) sums[i] / 10;        // 求当前行的均值
    }

    for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
            cout.width(2);                      // 限制显示时的每一个字符的宽度为2
            cout << twodee[i][j] << " ";
        }
        cout << ": sum = " << sums[i] << ", average = " << aves[i] << endl;
    }

    return 0;
}