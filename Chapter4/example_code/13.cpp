#include <iostream>
#include <string>

using namespace std;     

struct inflatable
{
    char name[20];    // 注意这里是字符串数组, 数组不能直接给数组赋值
    float volume;
    double price;

};                  

int main(void)
{
    inflatable bouquet =              
    {
        "sunflowers",  
        0.20,
        12.49             
    };              

    inflatable choice;     // 只进行了声明, 没有进行初始化

    cout << "bouquet: " << bouquet.name << " for $" << bouquet.price << endl;

    // 当结构体一样时, 可以直接将结构体赋值给结构体. (结构体对象之间支持直接赋值)
    choice = bouquet;    // 将 bouquet 的值直接赋值给 choice,  注意, 结构体内包含了字符串数组, 但是此时也可以直接进行赋值
    cout << "choice: " << choice.name << " for $" << choice.price << endl;

    return 0;
}