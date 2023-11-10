#include "winec.h"

/*
    在成员初始化列表中, 我们使用 valarray 的构造函数来完成类型转换:
        valarray<类型> 变量名字(数组名, 数组元素个数)
        valarray<类型> 变量名字(数组元素初始化的默认值, 数组元素个数)

        在代码中, 我们使用了私有继承, 所以这里就需要使用类名(而不是成员名)来获得基类的对象
*/
Wine::Wine(const char *l, int y, const int yr[], const int bot[]) : string(l), year(y), PairArray(ArrInt(yr, y), ArrInt(bot, y))
{
}

Wine::Wine(const char *l, int y) : string(l), year(y), PairArray(ArrInt(0, y), ArrInt(0, y))      // ArrInt(0, 0) 表示数组中所有元素都是初始化为0, 然后数组内部设置为没有元素
{
}

void Wine::GetBottles()
{
    cout << "Enter " << (const string &)*this << " data for " << year << endl;      // 用(const string &)*this 替代了 label, 通过强制类型转换可以获得基类的匿名对象
    for (int i = 0; i < year; i++){
        cout << "Enter year: ";
        cin >> PairArray::first()[i];       // 通过类名 + 作用域解析运算符 来调用基类的方法
        cout << "Enter bottles for that year: ";
        cin >> PairArray::second()[i];
    }
}

const string & Wine::Label() const
{
    return (const string &)*this;
}

int Wine::sum() const
{
    return PairArray::second().sum();     // // 通过类名 + 作用域解析运算符 来调用基类的方法, 并且使用 valarray<int> 类型提供的sum方法
}

void Wine::Show() const
{
    cout << "Wine: " << (const string &) *this << endl;         // 用(const string &)*this 替代了 label, 通过强制类型转换可以获得基类的匿名对象
    cout << "\t\t" << "Year\t\tBottles" << endl;
    for (int i = 0; i < year; i++){
        cout << "\t\t" << PairArray::first()[i] << "\t\t" << PairArray::second()[i] << endl;  // 通过类名 + 作用域解析运算符 来调用基类的方法
    }
}
