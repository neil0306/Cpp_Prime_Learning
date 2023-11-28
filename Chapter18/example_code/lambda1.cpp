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
#define SIZE 390000

bool f3(int x) {return x % 3 == 0;};
bool f13(int x) {return x % 13 == 0;};

int main(void)
{
    vector<int> numbers(SIZE);
    int count3 = 0;
    int count13 = 0;

    // ------- lambda表达式的方括号什么都不写 -------
    numbers.resize(SIZE);
    generate(numbers.begin(), numbers.end(), rand);  
    count3 = count_if(numbers.begin(), numbers.end(), [](int x){return x % 3 == 0;});   
    cout << "Count of numbers divisable by 3: " << count3 << endl;
    count13 = count_if(numbers.begin(), numbers.end(), [](int x){return x % 13 == 0;});   // 这里 f_mod(13) 是调用了构造函数创建了匿名对象
    cout << "Count of numbers divisable by 13: " << count13 << endl;

    // ------- lambda表达式的方括号写变量名, 按值传递 -------
    count13 = 0;
    for_each(numbers.begin(), numbers.end(), [&count13](int x){count13 += x % 13 == 0;});   
    /*
        lambda表达式里对 count13进行了修改;
        += 是一个赋值操作, 表达式从右往左运行, 其中 x % 13 == 0 属于右侧的表达式
        由于已经在 lambda 表达式中完成了计数, 所以此时只需要遍历即可, 换成 for_each
    */
    cout << "Count of numbers divisable by 13: " << count13 << endl;

    count3 = count13 = 0;
    for_each(numbers.begin(), numbers.end(), [&count3, &count13](int x){count3 += x % 3 == 0;count13 += x % 13 == 0;});   
    cout << "Count of numbers divisable by 3: " << count3 << endl;
    cout << "Count of numbers divisable by 13: " << count13 << endl;

    return 0;
}
