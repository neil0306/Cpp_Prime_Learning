#include <iostream>
#include <cstring>        // 字符串的操作函数

int main(void)
{
    using namespace std;

    const int SIZE = 20;
    char first_name[SIZE];
    char last_name[SIZE];
    char full_name[SIZE * 2];

    cout << "Enter your first name: ";
    cin.getline(first_name, SIZE);
    cout << "Enter your last name: ";
    cin.getline(last_name, SIZE);

    strcpy(full_name, last_name);   // strcpy(目标参数, 源参数)

    //字符串追加函数 strcat()
    strcat(full_name, ", ");        // 追加一个逗号和空格
    strcat(full_name, first_name);
    cout << "Here's the information in a single string: " << full_name << ".\n";

    return 0;
}