#include <iostream>

struct inflatable 
{
    char name[20];
    float volume;
    double price;
};


int main(void)
{
    using namespace std;

    inflatable *ps = new inflatable;

    cout << "Please enter Name of inflatable item: ";
    cin.get(ps -> name, 20);   // 调用cin中的get方法捕获输入的值, 存放到结构体的成员 name 中
    cout << "Enter Volume in cubic feet: ";
    cin >> (*ps).volume;       // 取出指针里的结构体, 直接使用成员运算符"."来访问结构体的成员
    cout << "Enter price $: ";
    cin >> ps -> price;       // 用对结构体指针使用箭头运算符访问price成员, 并将捕获的输入赋值给成员 price

    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " << ps -> volume << endl;
    cout << "Price: $" << (*ps).price << endl;

    // 由于前面用了new, 别忘了释放内存
    delete ps;              // 没有手动释放内存的话, 编译不会报错, 但是会留下安全隐患 

    return 0;
}