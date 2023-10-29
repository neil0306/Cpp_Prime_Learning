#include "studentc.h"

double Student::Average() const
{
    if (scores.size() > 0){
        return scores.sum() / scores.size();
    }
    else{
        return 0.0;
    }
}

const string &Student::Name() const
{
    return name;
}

// 这个函数返回的是可操作的左值
double & Student::operator[](int n)     // 注意返回的是引用
{
    return scores[n];
}

// 这个函数返回的是"不可写"的右值
double Student::operator[](int n) const // 按值返回, 不是引用
{
    return scores[n];
}

istream & operator>>(istream &is, Student &stu)
{
    is >> stu.name;
    return is;
}

istream & getline(istream &is, Student &stu)        // 重载了getline函数
{
    getline(is, stu.name);          // 这里调用的是原生的 getline 函数, 对应的函数声明是 getline(istream &, string &)
    return is;
}

ostream & operator<<(ostream &os, const Student &stu)
{
    os << "Scores for " << stu.name << ": " << endl;

    int limit = stu.scores.size();  // 获取科目的数量
    if (limit > 0)
    {
        int i = 0;
        for (i = 0; i < limit; i++){
            os << stu.scores[i] << " ";

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
