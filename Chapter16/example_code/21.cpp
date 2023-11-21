#include <iostream>
#include <algorithm>
#include <valarray>
#include <cstdlib>  // 为了使用rand

using namespace std;

typedef valarray<int> vint;
const int SIZE = 12;

void show(const vint &v, int cols);

int main(void)
{
    vint valint(SIZE);
    int i;
    for (i = 0; i < SIZE; i++){
        valint[i] = rand() % 10;
    }
    show(valint, 3);

    cout << "Second column: " << endl;
    valarray<int> vcol = valint[slice(1, 4, 3)]; // 从下标为1的位置开始取, 每隔3个数取一次, 每次取4个元素
    show(vcol, 1);
    return 0;
}

// 按列显示数组内容, 每行显示 cols 列
void show(const vint &v, int cols)
{
    int lim = v.size();
    int i;
    for (i = 0; i < lim; i++){
        cout << v[i];
        if(i % cols == cols -1){
            cout << endl;
        }
        else{
            cout << " ";
        }
        if(lim % cols != 0){    // 元素数量不够填满一行, 手动换行
            cout << endl;
        }
    }
}
