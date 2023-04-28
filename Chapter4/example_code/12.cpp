#include <iostream>
#include <string>

using namespace std;     // 命名空间如果写在这里, 之后的代码都能使用这个命名空间, 结构体中也就可以省略 std:: 这部分


// 结构体定义, 通常写在 main 函数外面(称为外部声明), 好处是整个文件都能使用这个结构体
struct inflatable
{
    // char name[20];  // 别忘了分号
    // std::string name;   // 使用 string 类型, 需要包含头文件 <string>, 如果std命名空间没有写在结构体定义之前, 就需要加上 std:: 这部分
    string name;
    float volume;
    double price;

};                  // 别忘了分号

int main(void)
{
    // using namespace std;

    //使用定义好的结构体
    struct inflatable guest =                   // 使用C语言的写法, 前面加上 struct
    {
        "Glorious Gloria",  // 给结构体成员赋值的时候, 不再是一条条语句, 所以这里用的是逗号 `,`
        1.88,
        29.99               // 最后已经没有值了, 所以最后的分号可以省略 (把这个想象成花括号赋值的语法)
    };              // 别忘了分号

    inflatable pal =                            // 使用 C++ 的写法, 省略struct
    {
        "Audacious Arthur",
        3.12, 
        32.99
    };              // 别忘了分号

    cout << "Expand your guest list with " << guest.name << " and " << pal.name << "!\n";
    cout << "You can have both for $" << guest.price + pal.price << "!\n";

    return 0;
}