#include <iostream>
using namespace std;

int main(void)
{
    double x;                // x = 3, 因為是兩個int相除, 得到的結果是 int(沒有小數), 然後隱式轉換到double, 所以丟失了小數點
    x = 10 / 3;     
    // x = (double)10 / 3;      // x = 3.3333, 3會先隱式地轉double, 再做10/3, 所以有小數
    cout << "x = " << x << endl;

    double y = static_cast<double>(10) / 3;        // C++ 推薦的規範寫法, 雖然結果與 (double)10/3 相同.
    cout << "y = " << y << endl;
    return 0;
}