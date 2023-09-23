#include <iostream>
#include <cstring>
#include "golf.h"

using namespace std;

void setgolf(golf &g, const char *name, int hc)
{
    strcpy(g.fullname, name);   // 字符串拷贝
    g.handicap = hc;
}

int setgolf(golf &g)
{
    int temp = 1;       // true
    cout << "The fullname is: ";
    cin.getline(g.fullname, Len);       // 捕获一整行

    // 比较字符串, 看看输入是否成功
    if(strcmp(g.fullname, "") == 0){
        cout << "invalid input! Ending this gold player info..." << endl;
        temp = 0;       // false
        return temp;
    }
    else{
        cout << "The handicap is: ";
        cin >> g.handicap;
        cin.get();              // 清除缓冲区里的回车
        return temp;
    }
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    cout << "The fullname is: " << g.fullname << endl;
    cout << "The Handicap is: " << g.handicap << endl;
}
