/*

*/
#include <iostream>

using namespace std;
char * buildStr(char c, int n);

int main(void)
{
    char ch;
    int times;

    cout << "Enter a character: ";
    cin >> ch;

    cout << "Enter a integer: ";
    cin >> times;

    char * ps = buildStr(ch, times);   // 这里调用函数, new了一个数组, 返回了数组指针
    cout << ps << endl;

    delete []ps;   // 释放 new 的数组
    return 0;
}

char * buildStr(char c, int n)
{
    char *pstr = new char[n+1];

    pstr[n] = '\0';  // 先填一个空字符
    for(int i = 0; i < n; i++)
        pstr[i] = c;

    return pstr;
}