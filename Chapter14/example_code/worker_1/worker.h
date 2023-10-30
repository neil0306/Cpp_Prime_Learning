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
    protected:
        virtual void Data() const;      // 模块化输出: 这里只输出自己的数据部分; 我们希望派生类也能实现不同的功能(多态), 于是定义成虚函数
        virtual void Get();       // 同上
    public:
        Worker() : fullname("none one"), id(0){}
        Worker(const string &s, long n) : fullname(s), id(n){}
        virtual ~Worker(){}

        virtual void Set() = 0;         // 纯虚函数(此时Worker就变成抽象基类, 不可再进行实例化)
        virtual void Show() const = 0;  // 纯虚函数(此时Worker就变成抽象基类, 不可再进行实例化)
};

// 继承虚基类 Worker
class Waiter : virtual public Worker            // 如果不写public, 则默认是private (私有继承)
{
    private:
        int panache;
    protected:
        virtual void Data() const;      // 模块化输出: 这里只输出自己的数据部分; 我们希望派生类也能实现不同的功能(多态), 于是定义成虚函数
        virtual void Get();       // 同上
    public:
        Waiter() : Worker(), panache(0){}
        Waiter(const string &s, long n, int p = 0) : Worker(s, n), panache(p){}
        Waiter(const Worker &wk, int p = 0 ) : Worker(wk), panache(p){}
        virtual ~Waiter(){}

        // Set和Show 也可以不加 virtual, 因为基类已经声明为虚函数
        virtual void Set();
        virtual void Show() const;
};

// 继承虚基类 Worker
class Singer : public virtual Worker
{
    protected:          // 保护成员: 可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问
        enum{other, alto, contralto, soprano, bass, baritone, tenor};
        enum{Vtypes = 7};
    private:
        // 静态数据成员在类声明中声明, 在包含类方法的文件中**初始化**(需用到作用域运算符::),
        //      如果静态成员是 int类型 或 enum const 类型, 则可以直接在类的声明中进行初始化.
        static const char *pv[Vtypes];
        int voice;
    protected:
        virtual void Data() const;      // 模块化输出: 这里只输出自己的数据部分; 我们希望派生类也能实现不同的功能(多态), 于是定义成虚函数
        virtual void Get();       // 同上
    public:
        Singer() : Worker(), voice(other){}
        Singer(const string &s, long n, int v = other) : Worker(s, n), voice(v){}
        Singer(const Worker &wk, int v = other) : Worker(wk), voice(v){}
        virtual ~Singer(){}

        // 本质上 Set和Show 都是虚函数, 只不过这里可以省略 virtual, 因为基类已经声明为virtual了
        void Set();      
        void Show() const; 
};


// 多重继承的派生类
class SingingWaiter : public Waiter, public Singer
{
    protected:  // 虽然没有属于自己的数据, 但由于基类已经把Data和Get定义为虚函数了, 所以派生类一定要有这两个函数
        virtual void Data() const {};      // 啥都不干就行, 但是不能缺
        virtual void Get() {};       // 啥都不干就行, 但是不能缺
    public:
        // 由于Singer和Waiter都采用了虚基类的写法, 所以这里会自动禁用"信息传递", 并允许使用间接基类(祖先基类)的构造函数 Worker(const string &, long n);
        SingingWaiter(){};
        SingingWaiter(const string &s, long n, int p = 0, int v = Singer::other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v){}
        SingingWaiter(const Worker &wk, int p = 0, int v = Singer::other) : Worker(wk), Waiter(wk, p), Singer(wk, v) {}

        virtual void Set();
        virtual void Show() const;      // 注意, 如果多重继承的派生类想要调用其中一个基类里的函数, 最安全的做法是使用作用域解析运算符(::)来避免二义性, 而为了避免多次输出基类的成员, 还推荐使用模块化拆分的方式
};

#endif //!__WORKER_H__