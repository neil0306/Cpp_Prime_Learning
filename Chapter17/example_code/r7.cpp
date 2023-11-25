#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void)
{
    string name;
    double hourly, hours;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your hourly wages: ";
    cin >> hourly;
    cout << "Enter number of hours worked: ";
    cin >> hours;

    cout << "First format: "<< endl;
    cout << fixed << showpoint;     // 不使用科学计数法 + 显示小数点
    // 默认右对齐, 第一字段宽30; 第二个字段宽20, 保留两位小数; 第三个字段宽10, 保留一位小数
    cout << setw(30) << name << ": " << setw(20) << setprecision(2) << hourly << setw(10) << setprecision(1) << hours << endl;

    cout << "Second format: " << endl;
    // 前面已经设置过不使用科学计数法 + 显示小数点
    cout << left;           // 设置为左对齐
    cout << setw(30) << name << ": " << setw(20) << setprecision(2) << hourly << setw(10) << setprecision(1) << hours << endl;

    return 0;
}
