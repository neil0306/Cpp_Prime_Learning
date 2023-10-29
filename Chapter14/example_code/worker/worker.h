#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
#include <string>

using namespace std;

class Worker
{
    private:
        string fullname;
        long id;
    public:
        Worker() : fullname("none one"), id(0){}
        Worker(const string &s, long n) : fullname(s), id(n){}
        virtual ~Worker(){}

        virtual void Set();
        virtual void Show() const;
};

class Waiter : public Worker            // 如果不写public, 则默认是private (私有继承)
{
    private:
        int panache;
    public:
        Waiter() : Worker(), panache(0){}
        Waiter(const string &s, long n, int p = 0) : Worker(s, n), panache(p){}
        Waiter(const Worker &wk, int p = 0 ) : Worker(wk), panache(p){}
        virtual ~Waiter(){}

        // Set和Show 也可以不加 virtual, 因为基类已经声明为虚函数
        virtual void Set();
        virtual void Show() const;
};

class Singer : public Worker
{
    protected:          // 保护成员: 可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问
        enum{other, alto, contralto, soprano, bass, baritone, tenor};
        enum{Vtypes = 7};
    private:
        // 静态数据成员在类声明中声明, 在包含类方法的文件中**初始化**(需用到作用域运算符::),
        //      如果静态成员是 int类型 或 enum const 类型, 则可以直接在类的声明中进行初始化.
        static const char *pv[Vtypes];
        int voice;
    public:
        Singer() : Worker(), voice(other){}
        Singer(const string &s, long n, int v = other) : Worker(s, n), voice(v){}
        Singer(const Worker &wk, int v = other) : Worker(wk), voice(v){}
        virtual ~Singer(){}

        // 本质上 Set和Show 都是虚函数, 只不过这里可以省略 virtual, 因为基类已经声明为virtual了
        void Set();      
        void Show() const; 
};

#endif //!__WORKER_H__