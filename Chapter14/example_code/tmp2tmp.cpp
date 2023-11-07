#include <iostream>

using namespace std;

template<class T>
void counts();

template<class U>
void reports(U &hf);         // 把U替换为模板类, 就等价于frnd2tmp.cpp例子里的友元函数的声明方式了

template <class V>
class HasFriend
{
    private:
        V item;
        static int ct;      // 相同的类会共用同一个 ct, 它的初始化要写到类的外面. 注意: HasFriend<int> 和 HasFriend<double> 是两个不同的类
    public:
        HasFriend(const V &i) : item(i){ ct++; }
        ~HasFriend(){ ct--; }

        friend void counts<V>();                    // display ct 
        friend void reports< HasFriend<V> >(HasFriend<V> &hf);      // display item
};

// 初始化静态成员变量
template <class T>
int HasFriend<T>::ct = 0;

// 把counts写成模板函数之后, 这里发生的不同现象是: HasFriend<int>, HasFriend<double> 这两种实例化就不再共用一个counts了 (没有定义成模板函数的时候, 由于入参没有限制, 它们用的是同一个counts函数)
// 由于template<class T> 进行了类型的约束, 所以不同的类型将使用各自的counts
template<class T>
void counts()
{
    cout << "count: " << HasFriend<T>::ct << endl;
}

template <class U>
void reports(U &hf)            // 注意: 这是 HasFriend<int> 的友元函数
{
    cout << hf.item << endl;
}

int main(void)
{
    cout << "No object declared: " << endl;
    counts<int>();

    cout << " ----- " << endl;

    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: " << endl;
    counts<int>();       // HasFriend<int>里的ct变成1
    reports(hfi1);

    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: " << endl;
    counts<int>();       // HasFriend<int>里的ct变成2
    reports(hfi2);

    cout << " ----- " << endl;

    HasFriend<double> hfdb(0.5);
    cout << "After hfdb declared: " << endl;
    counts<double>();       // HasFriend<double>里的ct变成1
    reports(hfdb);

    return 0;
}