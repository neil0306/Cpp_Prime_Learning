#include <iostream>
#include <ctime>

int main(void){
    using namespace std;

    cout << "Enter the delay time, in seconds: ";

    float secs;
    cin >> secs;

    clock_t delay = secs * CLOCKS_PER_SEC;  // 记录一秒要计数多少次. 注意这里使用的是 clock_t (本质上还是整型)

    clock_t start = clock();                // 这个语句记录了 当前时间 对应的统计次数, start 作为起始时间标记
    
    while (clock() - start < delay);        // 因为是延时循环, 所以这里搞了一个空循环语句, 后面加了分号
    
    cout << "done.\n";

    return 0;
}