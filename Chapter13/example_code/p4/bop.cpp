#include "bop.h"
#include <cstring>

Port::Port(const char * br, const char * st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    
    // 判断输入字符是否过长
    strncpy(style, st, 20);
    if (strlen(st) >= 20){
        style[19] = '\0';
    }
    else{
        style[strlen(st)] = '\0';
    }

    bottles = b;
}

Port::Port(const Port &p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port &p)
{
    if (this == &p){
        return *this;
    }

    delete [] brand;

    brand = new char[strlen(p.brand) +1];
    strcpy(brand, p.brand);

    strcpy(style, p.style);
    bottles = p.bottles;

    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    // 这里没考虑是否不能减的情况
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}


// 派生类
VintagePort::VintagePort() : Port()
{
    nickname = nullptr;
    year = 0;
}
VintagePort::VintagePort(const char * br, const char * st, int b, const char * nn, int y) : Port(br, st, b)
{
    nickname = new char[strlen(nn)+1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp){
        return *this;
    }

    Port::operator=(vp);

    delete [] nickname;
    nickname = new char[strlen(vp.nickname) +1];
    strcpy(nickname, vp.nickname);

    year = vp.year;

    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &) vp;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}