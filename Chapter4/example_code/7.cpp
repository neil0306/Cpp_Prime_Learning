#include <iostream>
#include <string>

int main(void)
{
    using namespace std;

    char charr1[20];
    char charr2[20] = "jaguar";

    string str1;                // 把string当做类型, 创建string对象 str1
    string str2 = "panther";    // 把string当做类型, 创建string对象 str2

    cout << "Enter a kind of feline: ";
    cin >> charr1;

    cout << "Enter another of feline: ";
    cin >> str1;                // 可以用 cin 来初始化string对象

    cout << "Here are some felines:\n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

    // 访问字符串内的某一个字符
    cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;  // 访问字符数组, 注意数组从0开始计数
    cout << "The third letter in " << str2 << " is " << str2[2] << endl;      // 访问string对象, 下标同样是从0开始计数

    return 0;
}