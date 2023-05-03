#include <iostream>
#include <string>        // string 类

int main(void)
{
    using namespace std;

    // const int SIZE = 20;
    // char first_name[SIZE];
    // char last_name[SIZE];
    // char full_name[SIZE * 2];

    string first_name, last_name, full_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);
    cout << "Enter your last name: ";
    getline(cin, last_name);

    // 字符串拼接
    // strcpy(full_name, last_name);   // strcpy(目标参数, 源参数)
    // //字符串追加函数 strcat()
    // strcat(full_name, ", ");        // 追加一个逗号和空格
    // strcat(full_name, first_name);
    full_name = last_name + ", " + first_name;          // 直接用 + 号 就可以实现字符串拼接

    cout << "Here's the information in a single string: " << full_name << ".\n";

    return 0;
}