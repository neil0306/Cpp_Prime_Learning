#ifndef __DMA_H__
#define __DMA_H__

#include <iostream>
using namespace std;

// 重新定义一个基类
class ABC
{
    private:
        char *label;
        int rating;
    public:
        ABC(const char *l = "null", int r = 0);     // 默认构造
        virtual ~ABC();                             // 基类就应该写一个虚析构函数
        
        ABC(const ABC &rs);
        ABC & operator=(const ABC &rs);             // 有复制构造函数就一定要重载赋值运算符
        
        friend ostream & operator<<(ostream &os, const ABC &rs);        // 输出

        // 新增一个虚方法
        virtual void View() const;
};

class baseDMA : public ABC          // 继承ABC类
{
    // 没有数据成员了(基类已经包含)

    public:
        baseDMA(const char *l = "null", int r = 0);     // 默认构造
        // 析构函数使用默认的就行, 因为没有new操作
        baseDMA(const baseDMA &rs);
        // 由于baseDMA 没有自己专属的数据成员, 可以使用默认的赋值运算符
        // 由于baseDMA 没有自己专属的数据成员, 不需要再重载输出了, 直接用基类的就行
        virtual void View() const;
};

// 不带new的派生类
class lacksDMA : public ABC
{
    private:
        enum {COL_LEN = 40};
        char color[COL_LEN];        // 这里已经分配好内存了. 没有动态分配内存, 可以不写当前派生类的析构函数
    public:
        lacksDMA(const char *l = "null", int r = 0, const char *c = "blank");
        lacksDMA(const ABC &rs, const char *c = "blank");
        // 注: 由于派生类中没有使用new为成员变量分配空间, 所以派生类可以不写复制构造函数; 同样也不需要重载赋值运算符
        friend  ostream & operator<<(ostream &os, const lacksDMA &rs);
        virtual void View() const;
}; 

// 带new的派生类
class hasDMA : public ABC
{
    private:
        char * style;
    public:
    hasDMA(const char *l = "null", int r = 0, const char *s = "null");
    hasDMA(const ABC &rs, const char *s);
    hasDMA(const hasDMA &hs);       // 复制构造函数
    virtual ~hasDMA();      // 由于这个派生类的数据成员是用了 new, 所以一定要自定义析构函数

    hasDMA & operator=(const hasDMA &hs);   // 重写了复制构造函数, 就一定要重写赋值运算符
    friend ostream & operator<<(ostream &os, const hasDMA &rs);
    virtual void View() const;
};

#endif //!__DMA_H__
