#include <iostream>

using namespace std;

template <class T1, class T2>
class A
{
    public:
        void show();
};

template <class T1, class T2>
void A<T1,T2>::show()
{
    cout << "use general definition" << endl;
}

// --- 显式实例化 ---
template class A<double, double>;       // 编译完之后, 这里马上就创建A<double,double>的类声明了


// --- 显式具体化: 针对int类型进行特殊的处理, 进行量身定制(修改类的声明) ---
template <>         // 没有写T1和T2, 表示这两个类型都需要特殊修改, 不使用模板里的操作
class A<int, int>
{
    public:
        void show();
};

void A<int,int>::show()
{
    cout << "use specialized definition." << endl;       // 显式具体化
}

// ---- 部分具体化: 只针对部分类型参数进行特殊处理, 模板里仍有未指定的类型 -----
template <class T1>           // 只针对T2这个类型进行具体化, 括号里只放 "不进行具体化的类型参数"
class A<T1, int>
{
    public:
        void show();

};

template<class T1>
void A<T1, int>::show()
{
    cout << "use partial specialized definition." << endl;
}

int main(void)
{
    // ----- 隐式实例化 ------
    A<char, char> a1;       
    a1.show();          // use general definition

    // ----- 显式实例化 ----
    A<int,int> a2;
    a2.show();          // use specialized definition

    // ------ 部分具体化 ----
    A<char, int> a3;
    a3.show();          // use partial specialized definition

    return 0;
}


