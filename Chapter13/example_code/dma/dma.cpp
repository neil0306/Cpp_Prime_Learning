#include "dma.h"
#include <cstring>      // strcpy 和 strlen 需要用到

baseDMA::baseDMA(const char *l, int r)
{
    label = new char [strlen(l) +1];
    strcpy(label,l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs)
{
    label = new char [strlen(rs.label) + 1];
    strcpy(label, rs.label);

    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA &rs)
{
    /*
        赋值运算符一共包含4步:
        1. 查看当前对象是否为自己本身
        2. 释放自身对象
        3. 开辟内存空间
        4. 拷贝数据
    */

    // step1:
    if (this == &rs){
        return *this;
    }

    // step2:
    delete [] label;

    // step3:
    label = new char[strlen(rs.label) + 1]; // +1 为空字符 '\0'

    // step4:
    strcpy(label, rs.label);
    rating = rs.rating;

    return *this;
}

ostream & operator<<(ostream &os, const baseDMA & rs)
{
    os << rs.label << endl;
    os << rs.rating << endl;
    return os;
}

lacksDMA::lacksDMA(const char *l, int r, const char *c) : baseDMA(l, r)
{
    strncpy(color, c, COL_LEN -1);      // 别忘记-1, 留给 '\0'
    color[COL_LEN -1] = '\0';
}

lacksDMA::lacksDMA(const baseDMA &rs, const char *c) : baseDMA(rs)
{
    strncpy(color, c, COL_LEN -1);      // 别忘记-1, 留给 '\0'
    color[COL_LEN -1] = '\0';
}

ostream & operator<<(ostream &os, const lacksDMA &ls)
{
    // 由于派生类无法直接访问基类的数据成员, 这里巧妙地是用了基类重载的输出运算符
    os << (const baseDMA &)ls;   // 把派生类强制类型转换成基类, 注意还是 const 并且是 引用!!
    os << ls.color << endl;
    return os;
}
