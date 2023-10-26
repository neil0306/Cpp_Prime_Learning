#ifndef __CLASSIC_H__
#define __CLASSIC_H__

#include <iostream>
using namespace std;

class Cd
{
    private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    public:
        // 构造函数不能是虚函数
        Cd(const char * s1, const char * s2, int n, double x);      // 普通构造
        Cd(const Cd & d);                                           // 拷贝构造
        Cd();                                                       // 默认构造
        virtual ~Cd(){};
        virtual void Report() const;
        Cd & operator=(const Cd &d);                    // 赋值运算符不能是虚函数(它左侧的对象随着类类型的不同而不同, 没必要定义成虚函数)
};

class Classic : public Cd
{
    private:
        char works[50];
    public:
        Classic();
        Classic(const Classic &c);
        Classic(const char *s1, const char *s2, const char *s3, int n, double x);
        ~Classic(){}
        virtual void Report();
        Classic &operator=(const Classic &c);
};

#endif //!__CLASSIC_H__