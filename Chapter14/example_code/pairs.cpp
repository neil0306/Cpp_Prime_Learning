#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Pair
{
    private:
        T1 a;
        T2 b;
    public:
        Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval){}
        T1 & first();
        T2 & second();
        T1 first() const{return a;}
        T2 second() const{return b;}
};

template <class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

// ---------------------------------- // 
int main(void)
{
    Pair<string, int> rating[4] = 
    {
        Pair<string, int>("Duck", 5),
        Pair<string, int>("Fresco", 4),
        Pair<string, int>("Cafe", 5),
        Pair<string, int>("Ears", 3)
    };

    int joins = sizeof(rating) / sizeof(Pair<string, int>);     // 统计元素个数

    for (int i = 0; i < joins; i++){
        cout << rating[i].second() << ":\t" << rating[i].first() << endl;
    }

    rating[3].first() = "fab";  // 左值, 调用的是 T1 & first()
    rating[3].second() = 6;     // 左值, 调用的是 T2 & second()

    cout << rating[3].second() << ":\t" << rating[3].first() << endl;

    return 0;
}