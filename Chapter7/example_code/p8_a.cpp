#include <iostream>
#include <string>

using namespace std;
const int SEASONS = 4;

void fill(double arr[], int size);
void show(const double arr[], int size);

const char* Snames[] = {"Spring", "Summer", "Fall", "Winter"};  // 初始化四个季节的名字

int main(void)
{
    double expenses[SEASONS];  // expenses 用来存放四个季节的开销
    fill(expenses, SEASONS);
    show(expenses, SEASONS);

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