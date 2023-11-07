#include <iostream>

using namespace std;

template<class T>
class ManyFriend
{
    private:
        T item;
    public:
        ManyFriend(const T &i) : item(i){}

        // 直接在 模板类中声明模板函数 并作为 友元函数
        template < class C, class D>
        friend void show2(C &, D &);


};

template <class C, class D>
void show2(C &c, D &d)
{
    cout << c.item << ", " << d.item << endl;
}

int main(void)
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);

    cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2);

    cout << "hfdb, hfi2: ";
    show2(hfdb, hfi2);

    return 0;
}

