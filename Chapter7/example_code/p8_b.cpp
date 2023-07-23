#include <iostream>
#include <string>

using namespace std;
const int SEASONS = 4;

void fill(double arr[], int size);
void show(const double arr[], int size);

const char* Snames[] = {"Spring", "Summer", "Fall", "Winter"};  // 初始化四个季节的名字

struct Spend            // 用结构体把原来的 expenses 包起来, 让它像array模板类
{
    double money[SEASONS];
};

int main(void)
{
    Spend expenses;
    // double expenses[SEASONS];  // expenses 用来存放四个季节的开销
    fill(expenses.money, SEASONS);
    show(expenses.money, SEASONS);

    return 0;
}

void fill(double arr[], int size)           // 要修改数组, 所以不加 const 做保护
{
    for(int i = 0; i < size; i++){
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> arr[i];
    }
}

void show(const double arr[], int size)
{
    double total = 0.0;
    cout << "EXPENSES: " << endl;
    for (int i = 0; i < size; i++){
        cout << Snames[i] << "\t: $" << arr[i] << endl;
        total += arr[i];
    }
    cout << "Total: " << total << endl;
}