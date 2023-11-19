#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string one("Lottery Winner.");      // 使用構造函數1: string(const char *s)
    cout << one << endl;

    string two(20, '$');                // 使用構造函數2: string(size_type n, char c)
    cout << two << endl;

    string three(one);
    cout << three << endl;              // 使用構造函數3: string(const string &str)

    one += " Oops!";                    // 加法運算符重載
    cout << one << endl;                // 調用 "<<" 重載函數, 在末尾追加字符串

    two = "Sorry, That was ";           // 調用賦值運算符, 重新賦值
    three[0] = 'P';                     // 替換第一個字符

    string four = two + three;          // 調用了構造函數4: string()
    cout << four << endl;

    char alla[] = "All's well that ends well.";
    string five(alla, 20);              // 調用了構造函數5: string(const char *s, size_type n).  注意: 數組名就是指針
    cout << five << endl;

    string six(alla + 6, alla + 10);    // 調用了構造函數6: template<class Iter> string (Iter begin, Iter end).   注意: 索引區間是 "左閉右開" 的
    cout << six << ", ";

    string seven(&five[6], &five[10]);  // 還是使用第六個構造函數, 本質上來說, 這個構造函數填入的參數都是地址
    cout << seven << "..." << endl;

    // 從 four 字符串的第7個字符開始, 往後面取16個字符出來, 賦值給 eight
    string eight(four, 7, 16);          // 構造函數7: string(const string &str, string size_type pos = 0, size_type n = npos)
    cout << eight << endl;

    // C++ 11新增的構造函數
    // 新增1: 移動構造函數 string(string && str) noexcept, 這個構造函數的效果類似於拷貝構造, 但是它的入參不是 const, 意味著輸入的參數 str 是可以修改的(這裡會把str幹掉)
        // 在 18章 再詳細討論

    // 新增2: string(initializer_list<char> il)
    // string piano_man = {'L', 'i', 's', 'z', 't'};   // 其實就是允許一個個字符拼一起來初始化一個字符串

    return 0;
}