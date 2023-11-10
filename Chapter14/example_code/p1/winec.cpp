#include "winec.h"

/*
    在成员初始化列表中, 我们使用 valarray 的构造函数来完成类型转换:
        valarray<类型> 变量名字(数组名, 数组元素个数)
        valarray<类型> 变量名字(数组元素初始化的默认值, 数组元素个数)

        在代码中, 我们使用了typdef改名, 所以下面的 ArrInt(yr, y) 就是在使用 valarray 的构造函数
*/
Wine::Wine(const char *l, int y, const int yr[], const int bot[]) : label(l), year(y), info(ArrInt(yr, y), ArrInt(bot, y))
{
}

Wine::Wine(const char *l, int y) : label(l), year(y), info(ArrInt(0, y), ArrInt(0, y))      // ArrInt(0, 0) 表示数组中所有元素都是初始化为0, 然后数组内部设置为没有元素
{
}

void Wine::GetBottles()
{
    cout << "Enter " << label << " data for " << year << endl;
    for (int i = 0; i < year; i++){
        cout << "Enter year: ";
        cin >> info.first()[i];
        cout << "Enter bottles for that year: ";
        cin >> info.second()[i];
    }
}

const string & Wine::Label() const
{
    return label;
}

int Wine::sum() const
{
    return info.second().sum();     // 使用 valarray<int> 类型提供的sum方法
}

void Wine::Show() const
{
    cout << "Wine: " << label << endl;
    cout << "\t\t" << "Year\t\tBottles" << endl;
    for (int i = 0; i < year; i++){
        cout << "\t\t" << info.first()[i] << "\t\t" << info.second()[i] << endl;
    }
}
