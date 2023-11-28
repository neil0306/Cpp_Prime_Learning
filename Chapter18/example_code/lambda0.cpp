/*
    用三种不同的方式完成: 
        统计随机数中能被 3 和 13 整除的值的个数.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
#define SIZE1 39
#define SIZE2 3900
#define SIZE3 390000

bool f3(int x) {return x % 3 == 0;};
bool f13(int x) {return x % 13 == 0;};

int main(void)
{
    vector<int> numbers(SIZE1);

    // ------- method 1: 使用函数指针来实现 -------
    srand(time(0));
    generate(numbers.begin(), numbers.end(), rand);     // 第三个参数是 "函数名/函数指针" (函数名就是一个指针/地址).   这个函数在中文书 page 894
    cout << "Sample size = " << SIZE1 << endl;
    int count3 = count_if (numbers.begin(), numbers.end(), f3);  // 统计指定范围内满足自定义函数的值有多少个, 要求这个函数返回值是 bool 类型.   中文书 page 888.
    cout << "Count of numbers divisable by 3: " << count3 << endl;
    int count13 = count_if (numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisable by 13: " << count13 << endl;

    // ------- method 2: 用函数符(仿函数)的方式 -------
    class f_mod
    {
        private:
            int div;        // 保存要设置的除数
        public:
            f_mod(int d = 1) : div(d){}
            bool operator()(int x){ return x % div == 0; }         // 函数符: 一定要重载 ()运算符 
    };
    numbers.resize(SIZE2);
    generate(numbers.begin(), numbers.end(), rand);                // 重新填充

    // 注意这个功能是C++11新增的, 有些编译器编译的时候可能需要使用 -std=c++11
    count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));   // 这里 f_mod(3) 是调用了构造函数创建了匿名对象
    cout << "Count of numbers divisable by 3: " << count3 << endl;
    count13 = count_if(numbers.begin(), numbers.end(), f_mod(13));   // 这里 f_mod(13) 是调用了构造函数创建了匿名对象
    cout << "Count of numbers divisable by 13: " << count13 << endl;

    // ------- method 3: 使用Lambda表达式 -------
    numbers.resize(SIZE3);
    generate(numbers.begin(), numbers.end(), rand);  
    count3 = count_if(numbers.begin(), numbers.end(), [](int x){return x % 3 == 0;});   
    cout << "Count of numbers divisable by 3: " << count3 << endl;
    count13 = count_if(numbers.begin(), numbers.end(), [](int x){return x % 13 == 0;});   // 这里 f_mod(13) 是调用了构造函数创建了匿名对象
    cout << "Count of numbers divisable by 13: " << count13 << endl;

    return 0;
}
