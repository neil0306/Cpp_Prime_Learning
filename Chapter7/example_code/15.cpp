#include <iostream>
#include <array>
#include <string>

using namespace std;
const int SEASONS = 4;

void fill(array<double, SEASONS> *pa);
void show(array<double, SEASONS> da);

const array<string, SEASONS> Snames = {"Spring", "Summer", "Fall", "Winter"};  // 初始化四个季节的名字

int main(void)
{
    array<double, SEASONS> expenses;  // expenses 用来存放四个季节的开销
    fill(&expenses);                  // 防止拷贝, 传指针
    show(expenses);

    return 0;
}

void fill(array<double, SEASONS> *pa)           // 要修改数组, 所以不加 const 做保护
{
    for(int i = 0; i < SEASONS; i++){
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];                        // (*pa) 先将指针转换为 array 对象, 只有 array 对象可以像数组一样操作, 但是array指针是不可以直接像指针一样的操作的, 因为array指针"并不表示第数组的第一个元素的地址"!
    }
}

void show(array<double, SEASONS> da)
{
    double total = 0.0;
    cout << "EXPENSES: " << endl;
    for (int i = 0; i < SEASONS; i++){
        cout << Snames[i] << "\t: $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total: " << total << endl;
}