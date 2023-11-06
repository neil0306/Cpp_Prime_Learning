#include <iostream>

using namespace std;

// 定义一个模板类
template <class T>
class beta
{
    private:
        // 在模板类中, 再定义一个模板类作为数据成员
        template <class V>
        class hold
        {
            private:
                V val;
            public:
                hold(V v = 0) : val(v){}
                void show() const {cout << val << endl;}
                V Value() const {return val;}
        };

        // 这里才是正式定义数据成员
        hold<T> q;      // 基于T类型创建一个 hold<T> 类型的对象, 它要在生成 beta 类的时候才会确定到底是什么类型
        hold<int> n;    // 基于int类型创建一个 hold<int> 类型的对象
    public:
        beta(T t, int i) : q(t), n(i){}     // 注意这里的 q 是基于T类型去生成hold<T>类型, 然后才创建的对象, 所以这里传参的时候t写的是T类型; i也是相同道理
        void Show() const {q.show(); n.show();}     // 注意这里是通过类的对象调用成员函数的方式来实现显式

        // 定义 模板函数 作为 成员函数
        template <class U>
        U blab(U u, T t){return ((q.Value() + n.Value()) * u / t);}
};

int main(void)
{
    // ---- 测试内部模板类 ------
    beta<double> guy(3.5, 3);
    /*
        针对这行代码的解析:
            1. 实例化了beta这个类模板, 此时编译器将生成 beta<double> 类
            2. 在实例化beta类的过程中, 对内部的 hold 模板也进行实例化, 此时编译器生成 hold<double> 类型, 其内部的数据成员val将使用double类型, 然后生成了对象q, q为hold<double> 类型.
            3. 继续实例化 beta<double>, n是 hold<int>类型, 它内部的数据成员val是int类型.

            注意: 由于 beta<double> 的构造函数声明对应为 beta(double, int), 所以传参的时候第一个是3.5(double类型), 另一个是 3(int类型)
    */

    cout << "T was set to double." << endl;
    guy.Show();

    // --- 测试模板(成员)函数 -----
    cout << "---------" << endl;
    cout << "V == T, they are all double" << endl;
    cout << "U was set to int, so output value is int type." << endl; 
    cout << guy.blab(10, 2.3) << endl;
    /*
        针对这行代码的解析:
            1. guy已经是 beta<double> 类型, 所以在调用blab函数的时候, 对应的blab函数模板会进行实例化
            2. guy.blab(10, 2.3)这行代码意味着blab的声明变成 "int blab(int, double)"
            3. blab函数的return语句中, 它的类型对应是 "(double + int) * int / double", 这行语句得到double类型,
            4. 但是blab函数返回值限制为int类型, 因此, 最后真正得到的类型是int类型 (发生了隐式类型转换)
    */

    cout << "U was set to double, so output value is double type." << endl; 
    cout << guy.blab(10.0, 2.3) << endl;

    return 0;
}