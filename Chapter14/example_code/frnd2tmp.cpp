#include <iostream>

using namespace std;

template <class T>
class HasFriend
{
    private:
        T item;
        static int ct;      // 相同的类会共用同一个 ct, 它的初始化要写到类的外面. 注意: HasFriend<int> 和 HasFriend<double> 是两个不同的类
    public:
        HasFriend(const T &i) : item(i){ ct++; }
        ~HasFriend(){ ct--; }

        friend void counts();                       // display ct 
        friend void reports(HasFriend<T> &hf);      // display item

};

// 初始化静态成员变量
template <class T>
int HasFriend<T>::ct = 0;

// 由于它是模板类的友元函数, 并且没有明显地做任何类型参数的限制, 所以对于 HasFriend<int>, HasFriend<double> 这些不同的实例化来说, 它们的对象使用的都是同一个友元函数
// 这个函数将输出所有模板类的对象个数 
void counts()
{
    cout << "int count: " << HasFriend<int>::ct << ", ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int> &hf)            // 注意: 这是 HasFriend<int> 的友元函数
{
    cout << "HasFriend<int> item: " << hf.item << endl;
}

void reports(HasFriend<double> &hf)         // 注意: 这是 HasFriend<double> 的友元函数
{
    cout << "HasFriend<double> item: " << hf.item << endl;
}

int main(void)
{
    cout << "No object declared: " << endl;
    counts();

    cout << " ----- " << endl;

    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: " << endl;
    counts();       // HasFriend<int>里的ct变成1
    reports(hfi1);

    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: " << endl;
    counts();       // HasFriend<int>里的ct变成2
    reports(hfi2);

    cout << " ----- " << endl;

    HasFriend<double> hfdb(0.5);
    cout << "After hfdb declared: " << endl;
    counts();       // HasFriend<double>里的ct变成1
    reports(hfdb);

    return 0;
}