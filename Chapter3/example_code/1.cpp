#include <iostream>
#include <climits>  // 这个库来自C语言

using namespace std;

int main(void)
{
    int n_int = INT_MAX;  // 从 climits 库中获取的常量变量
    int n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    
    // sizeof 只是一个运算符, 查看变量的时候可以不加括号, 但是查看类型的时候 **必须** 加括号
    cout << "int is " << sizeof(int) << " bytes." << endl;       // 在mac系统和Ubuntu系统的编译器中, int 都占据 4 各个byte
    cout << "short is " << sizeof n_short << " bytes." << endl;  // 在 mac 系统里, short 占用 4个byte, Ubuntu里是2个byte
    cout << "long is " << sizeof n_long << " bytes." << endl;    // 在 mac 系统里, long 占用 8个byte (32位), 和 Ubuntu一样, 符合规定
    cout << "long long is " << sizeof n_llong << " bytes." << endl; // 在 mac 系统里, long long 占用 8个byte (32位, 至少和long一致), 和 Ubuntu一样, 符合规定
    


    cout << "Maximun value of int: "
        << n_int        // 2147483647
        << endl;
    cout << "Maximun value of short: " 
        << n_short      // 32767
        << endl;
    cout << "Maximun value of long:"
        << n_long       // 9223372036854775807
        << endl;
    cout << "Maximum value of long long: "
        << n_llong      // 9223372036854775807
        << endl;


    // 测试赋值方法
    int n (3);           // 使用圆括号进行初始化
    cout << "n is: "
        << n
        << endl;
    
    int a = {3};         // 在 C++11 中, 可以使用花括号进行初始化, 
    // int b {4};           // mac上可能装的C++版本不够高, 忽略等号(=)的时候报错了.
    cout << "a is: "
        << a
        << endl;

    return 0;
}

