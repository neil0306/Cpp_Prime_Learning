#ifndef __DMA_H__
#define __DMA_H__

#include <iostream>
using namespace std;

class baseDMA
{
    private:
        char *label;
        int rating;
    public:
        baseDMA(const char *l = "null", int r = 0);     // 默认构造
        virtual ~baseDMA();                             // 基类就应该写一个虚析构函数
        
        baseDMA(const baseDMA &rs);
        baseDMA & operator=(const baseDMA &rs);         // 有复制构造函数就一定要重载赋值运算符
        
        friend ostream & operator<<(ostream &os, const baseDMA &rs);        // 输出
};

// 不带new的派生类
class lacksDMA : public baseDMA
{
    private:
        enum {COL_LEN = 40};
        char color[COL_LEN];        // 这里已经分配好内存了. 没有动态分配内存, 可以不写当前派生类的析构函数
    public:
        lacksDMA(const char *l = "null", int r = 0, const char *c = "blank");
        lacksDMA(const baseDMA &rs, const char *c = "blank");
        // 注: 由于派生类中没有使用new为成员变量分配空间, 所以派生类可以不写复制构造函数; 同样也不需要重载赋值运算符
        friend  ostream & operator<<(ostream &os, const lacksDMA &rs);
}; 

// 带new的派生类



#endif //!__DMA_H__
