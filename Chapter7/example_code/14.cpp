#include <iostream>
#include <string>

using namespace std;
const int SIZE = 5;

void display(const string *sa, int n);  // 用 const 保护数组

int main(void)
{
    string list[SIZE];  // 用 list 来存放数组
    cout << "Enter " << SIZE << " favorite foods:" << endl;

    for(int i = 0; i < SIZE; i++ ){
        cout << i + 1 << ": ";
        getline(cin, list[i]);      // 用 getline 函数捕获整行
    }

    cout << "Your list:" << endl;
    display(list, SIZE);

    return 0;
}

void display(const string *sa, int n)
{
    for(int i = 0; i < n; i++)
        cout << i + 1 << ": " << sa[i] << endl;  // 遍历并打印整个string对象
}