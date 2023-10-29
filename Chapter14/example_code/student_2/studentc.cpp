#include "studentc.h"

double Student::Average() const
{
    // if (scores.size() > 0){
    //     return scores.sum() / scores.size();
    // }
    // else{
    //     return 0.0;
    // }

    if (ArrayDb::size() > 0){
        return ArrayDb::sum() / ArrayDb::size();
    }
    else{
        return 0.0;
    }
}

const string & Student::Name() const
{
    return (const string &)(*this);     // 通过强制类型转换的方式获得从string继承而来的隐式对象
}

// 这个函数返回的是可操作的左值
double & Student::operator[](int n)     // 注意返回的是引用
{
    return ArrayDb::operator[](n);      // scores[n] 本质上就是在调用基类重载的运算符[], 因此这里直接使用 "类名::" 的方式替换
}

// 这个函数返回的是"不可写"的右值
double Student::operator[](int n) const // 按值返回, 不是引用
{
    return ArrayDb::operator[](n);      // 理由同上
}

// 友元函数 (注意它不属于成员函数, 不能直接使用私有基类的方法!)
istream & operator>>(istream &is, Student &stu)
{
    is >> (string &)stu;                // 强制类型转换之后, 得到的string类型的引用本质上等价于 此前的 name 成员
    return is;
}

istream & getline(istream &is, Student &stu)        // 重载了getline函数
{
    getline(is, (string &)stu);          // 这里调用的是原生的 getline 函数, 对应的函数声明是 getline(istream &, string &)
    return is;
}

// 友元函数
ostream & operator<<(ostream &os, const Student &stu)
{
    os << "Scores for " << (const string &)stu << ": " << endl;

    // ---- 方案1 ----
    // 原来写在这里的代码由于不能访问私有基类的方法, 所以把这部分代码写到了派生类的 arr_out 函数中, 此时就能间接访问了(曲线救国)
    // stu.arr_out(os);
    // -------------

    // ---- 方案2 ----
    int i = 0;
    int limit = stu.size();     // 用 using 声明为 public方法 之后就能使用私有基类的 size方法
    if (limit > 0){
        for (i = 0; i < limit; i++){
            os << stu.operator[](i) << " ";   // 用 using 声明为 public方法 之后就能使用私有基类的[]运算符

            // 每显示5门成绩就换行
            if (i % 5 == 4){        // 因为索引从0开始, 所以当余数为4时, 说明当前刚好显示了5门成绩
                os << endl;
            }
        }

        // 如果课程数量不是5的整数倍, 则需要额外换行一次
        if (i % 5 != 0){
            os << endl;
        }
    }
    else{
        os << "Empty array!" << endl;
    }
    // -------------

    return os;
}

// 使友元函数能调用 私有基类方法 的 "解决方案1" (方案2在头文件)
ostream & Student::arr_out (ostream &os) const
{
    int limit = ArrayDb::size();  // 获取科目的数量
    if (limit > 0)
    {
        int i = 0;
        for (i = 0; i < limit; i++){
            os << ArrayDb::operator[](i) << " ";

            // 每显示5门成绩就换行
            if (i % 5 == 4){        // 因为索引从0开始, 所以当余数为4时, 说明当前刚好显示了5门成绩
                os << endl;
            }
        }

        // 如果课程数量不是5的整数倍, 则需要额外换行一次
        if (i % 5 != 0){
            os << endl;
        }
    }
    else{
        os << "Empty array!" << endl;
    }

    return os;
}
