#include <iostream>

const int Cities = 5;
const int Years = 4;


int main(void){

    using namespace std;

    // 定义一个"字符串数组" 或 "字符指针数组"
    // 注意, 由于字符串是"常量", 所以这种数组通常是不更改里面的元素的, 前面要加一个 const 修饰
    const char * cities[Cities] = {   // 注意这是一个字符指针数组, 数组的每一个元素都是指针, 数组名的c是小写的
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };

    int maxtemps[Years][Cities] = {
        {96, 100, 87, 101, 105},
        {96, 98, 91, 107, 104},
        {97, 101, 93, 108, 107},
        {98, 103, 95, 109, 108}
    };

    cout << "City: Maximum temperature (F) for 2008 - 2011 \n";

    // 遍历二维数组, 我们希望先显示城市(第一列), 然后再显示不同年份的温度数据
    // 因此, 我们打印的时候是按列来打印(外层循环是列, 内层循环是行)
    for ( int city = 0; city < Cities; city ++){
        cout << cities[city] << ":\t";  // 注意, cities 数组可以看成只有1列, 但是有5行, 用 \t 制表符让输出格式对齐
        
        // 内层循环, 按行打印温度
        for (int year = 0; year < Years; year ++){
            cout << maxtemps[year][city] << "\t";   // 行变化, 列不变(由外层循环控制); 这里用了制表符 \t, 让输出数字对齐 
        }
        cout << endl;
    }
    return 0;
}
