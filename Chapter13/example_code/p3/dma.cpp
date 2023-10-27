#include "dma.h"
#include <cstring>      // strcpy 和 strlen 需要用到

ABC::ABC(const char *l, int r)
{
    label = new char[strlen(l) +1];
    std::strcpy(label,l);
    rating = r;
}

ABC::ABC(const ABC &rs)
{
    label = new char [strlen(rs.label) + 1];
    std::strcpy(label, rs.label);

    rating = rs.rating;
}

ABC::~ABC()
{
    delete [] label;
}

ABC & ABC::operator=(const ABC &rs)
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
    std::strcpy(label, rs.label);
    rating = rs.rating;

    return *this;
}

ostream & operator<<(ostream &os, const ABC & rs)
{
    os << rs.label << endl;
    os << rs.rating << endl;
    return os;
}

void ABC::View() const
{
    cout  << label << endl;
    cout  << rating << endl;
}


// 派生类1
baseDMA::baseDMA(const char *l, int r) : ABC(l, r)
{}

baseDMA::baseDMA(const baseDMA &rs) : ABC(rs)
{
}

void baseDMA::View() const
{
    ABC::View();
}

// 派生类2
lacksDMA::lacksDMA(const char *l, int r, const char *c) : ABC(l, r)
{
    strncpy(color, c, COL_LEN -1);      // 别忘记-1, 留给 '\0'
    color[COL_LEN -1] = '\0';
}

lacksDMA::lacksDMA(const ABC &rs, const char *c) : ABC(rs)
{
    strncpy(color, c, COL_LEN -1);      // 别忘记-1, 留给 '\0'
    color[COL_LEN -1] = '\0';
}

ostream & operator<<(ostream &os, const lacksDMA &ls)       // 派生类友元函数 调用 基类友元函数
{
    // 由于派生类无法直接访问基类的数据成员, 这里巧妙地是用了基类重载的输出运算符
    os << (const ABC &)ls;   // 把派生类强制类型转换成基类, 注意还是 const 并且是 引用!!
    os << ls.color << endl;
    return os;
}

void lacksDMA::View() const
{
    ABC::View();
    cout << color << endl;
}


// 派生类3
// 使用了 new 的派生类 hasDMA
hasDMA::hasDMA(const char *l, int r, const char *s) : ABC(l,r)
{
    style = new char[strlen(s) +1];
    strcpy(style, s);
}

hasDMA::hasDMA(const ABC &rs, const char *s) : ABC(rs)
{
    style = new char[strlen(s) +1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : ABC(hs)          // 利用基类可以兼容派生类的规则, 这里会触发基类的复制构造函数
{
    cout << "Copy construct function." << endl;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA &hs)
{
    // 赋值运算符重载一共4步: 1. 检查是否为当前对象; 2. 释放此前new的空间; 3. 开辟新的空间; 4.拷贝数据
    // step1
    if (this == &hs){
        return *this;
    }

    // step2
    ABC::operator=(hs);     // 这里面会包含基类new出来的对象的释放, 拷贝等步骤
    /*
    使用重载运算符有两种方法: 
        1. 运算符表示法;
        2. 函数表示法
        注意: 
            这里只能使用函数表示法, 因为运算符表示法没办法指定是基类的还是派生类的运算符.
            在调用基类重载的赋值运算符过程中, 在重载函数内部, 隐藏的参数this会指向当前需要拷贝数据的对象, 因此我们可以不用接它的返回值.
                形象地说: n1 = n2 这个语句中, =号被替换为 baseDMA::operator=, 而 n1 是在operator=这个函数里面用 this 来替换的
    */
    delete [] style;

    // step3
    style = new char[strlen(hs.style) + 1];

    // step4
    strcpy(style, hs.style);

    return *this;
}

ostream & operator<<(ostream &os, const hasDMA &rs)
{
    os << (const ABC &) rs;   // 先转基类, 然后触发基类的重载运算符
    os << "Style: " << rs.style << endl;
    return os;
}

void hasDMA::View() const
{
    ABC::View();
    cout << style << endl;
}
