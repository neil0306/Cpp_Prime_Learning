#include <cstring>
#include <iostream>

using namespace std;

class Frabjous
{
    private:
        char fab[20];
    public:
        Frabjous(const char *s = "C++")
        {
            strncpy(fab, s, 19);
            fab[19] = '\0';
        }
        virtual void tell() {cout << fab << endl;}
};

class Gloam : private Frabjous
{
    private:
        int glip;
    public:
        Gloam(int g = 0, const char *s = "C++");
        Gloam(int g, const Frabjous &f);
        void tell();
};

// 考察私有继承
Gloam::Gloam(int g, const char *s) : glip(g), Frabjous(s)           // 1. 必须使用成员初始化列表; 2. 使用基类类名来调用私有基类的构造函数, 从而实现成员初始化
{}

Gloam::Gloam(int g, const Frabjous &f): glip(g), Frabjous(f)
{}

void Gloam::tell()
{
    cout << glip << endl;
    Frabjous::tell();           // 用基类类名来调用私有基类的接口
}

int main(void)
{
    Gloam a(123, "Test C++");
    a.tell();
    return 0;
}
