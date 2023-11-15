#include <iostream>

using namespace std;

int main(void)
{
    int a = 10;

    cout << "a = " << a << endl;

    const int *p1 = &a; // 此時不允許通過 p1 指針來修改a的值, 但是 p1 還是可以指向其他int變量的
    // *p1 = 20;   // 編譯會報錯, 因為p1是 const int *
    int *p2 = const_cast<int *>(p1);    // p1 從 const int * 轉換為 int *

    *p2 = 20;
    cout << "a = " << a << endl;        // 此時輸出 a = 20

    return 0;
}