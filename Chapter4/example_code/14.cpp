#include <iostream>

using namespace std;
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(void)
{
    inflatable guest[3] =
    {
        {"Glorious Gloria", 1.88, 29.99},
        {"Godzilla", 2000, 565.99}           // 实验结果表明, 如果结构体数组中有元素没有初始化的话, 里面的数值成员会变成0, 字符串的话, 会变成"空字符串" 
    };
    cout << "The guests " << guest[0].name << " and " << guest[1].name << " have a combined volume of " 
        << guest[0].volume + guest[1].volume << " cubic feet.\n\n";

    // 下面测试一下结构体数组中没有初始化的元素的值
    cout << "The elements of the Third guest are: \n"
        << "Name: " << guest[2].name << "\n"
        << "volume: " << guest[2].volume << "\n"
        << "price: " << guest[2].price << ".\n";

    return 0;
}