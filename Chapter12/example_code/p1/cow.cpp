#include "cow.h"
#include <cstring>      // 使用 strncpy, 指定拷贝长度

Cow::Cow()
{
    name[0] = '\0';
    hobby = nullptr;
    weight = 0.0;
}

Cow::Cow(const char *nm, const char * ho, double wt)
{
    // name 用的是浅拷贝, 只拷贝了内容, 没有新增空间
    strncpy(name, nm, 20);
    if(strlen(nm) >= 20){
        name[19] = '\0';        // 如果nm里面的字符串长度 >= 20, 则name的最后一个字符改为空字符
    }

    // hobby 使用深拷贝, 不仅拷贝内容, 还要新开辟空间
    hobby = new char [strlen(ho) + 1];  // 动态开辟空间
    strcpy(hobby, ho);

    weight = wt;
}

Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow & Cow::operator=(const Cow &c)
{
    // step1: 防止自己拷贝给自己
    if(this == &c){
        return *this;
    }

    // step2: 如果需要赋值, 则首先释放掉涉及动态开辟内存的数据成员, 然后重新开辟空间&拷贝数据
    delete [] hobby;
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);

    // step3: 处理其他常规数据成员
    strcpy(name, c.name);
    weight = c.weight;

    // step4: 返回当前对象的内容, 注意不是返回this指针
    return *this;
}

void Cow::ShowCow() const
{
    cout << "Name: " << name << endl;
    cout << "Hobby: " << hobby << endl; 
    cout << "Weight: " << weight << endl; 
}