#ifndef __P2_H__
#define __P2_H__

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        static const int LIMIT = 25;        // 用 static 定义常量
        string lname;
        char fname[LIMIT];

    public:
        Person() {lname = ""; fname[0] = '\0';} // 默认构造函数, 放在这里会自动变成内联函数(inline)
        Person( const string &ln, const char *fn = "Heyyou");   // 自定义的构造函数
        void show() const;
        void FormalShow() const;
};

#endif
