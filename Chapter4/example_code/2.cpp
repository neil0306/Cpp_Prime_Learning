#include <iostream>
#include <cstring>

int main(void)
{
    using namespace std;

    const int SIZE = 15;

    char name1[SIZE];
    char name2[SIZE] = "C++owboy";

    cout << "Howdy! I'm " << name2 << ". What is your name? \n";
    cin >> name1;   // basicman
    cout << "Well, " << name1 << " your name has " << strlen(name1) << " letters and is stored\n"; // 打印 8, strlen 计算的是字符串的长度, 而且是**可见字符**的长度, 空字符不会被统计
    cout << "Your name is stored in an array, which is " << sizeof(name1) << " bytes long.\n";     // 打印 15, 这是整个数组的大小, byte为单位 

    return 0;
}