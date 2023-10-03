#include "golf.h"

golf::golf()
{
    cout << "The fullname is: ";
    cin.getline(fullname, Len);       // 捕获一整行

    cout << "The handicap is: ";
    cin >> handicap;
    cin.get();              // 清除缓冲区里的回车
}

golf::golf(const char *name, int hc)
{
    strcpy(fullname, name);   // 字符串拷贝
    handicap = hc;
}

void golf::setHandicap(int hc)
{
    handicap = hc;
}

void golf::showgolf() const
{
    cout << "The fullname is: " << fullname << endl;
    cout << "The Handicap is: " << handicap << endl;
}
