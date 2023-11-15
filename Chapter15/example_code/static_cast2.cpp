#include <iostream>

using namespace std;

// 假設有下面兩個類, 並且具有 A -> B 的繼承關係
class A     // 基類
{};

class B : public A      // 派生類
{};

class C     // C 與 A,B 沒有任何關係
{};

int main(void)
{
    A a;
    B b;
    A *pa = static_cast<A *>(&b);        // 向上轉換: 派生類指針轉基類指針
    B *pb = static_cast<B *>(&a);        // 向下轉換: 基類指針轉派生類指針

    // C *pc = static_cast<C*>(&a);        // 編譯報錯, 因為 C 與 A 類沒有任何關係!
    return 0;
}