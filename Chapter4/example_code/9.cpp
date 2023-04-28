#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
    using namespace std;

    char charr1[20];
    char charr2[20] = "jaguar";

    string str1;                // 把string当做类型, 创建string对象 str1
    string str2 = "panther";    // 把string当做类型, 创建string对象 str2

    // 赋值
    str1 = str2;
    strcpy(charr1, charr2);      // 调用 cstring 中的 strcp 函数, 把 charr2 的内容复制到 charr1 中

    // 拼接
    str1 += " paste";           // 追加 字符串常量
    strcat(charr1, " juice");   // 调用 cstring 中的 strcat 函数, 把 " juice" 追加到 charr1 中

    // 计算长度
    int len1 = str1.size();     // 调用 string 中的 size 函数, 计算 str1 的长度
    int len2 = strlen(charr1);  // 调用 cstring 中的 strlen 函数, 计算 charr1 的长度, 注意charr1是一个字符数组

    cout << "The string " << str1 << " contains " << len1 << " characters.\n";   // 13 characters
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n"; // 12 characters

    return 0;
}