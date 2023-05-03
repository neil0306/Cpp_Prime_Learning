#include <iostream>
#include <string>

int main(void)
{
    using namespace std;
    // const int ArSize = 20;

    // char name[ArSize];
    // char dessert[ArSize];

    string name;
    string dessert;

    cout << "Enter you name: \n";
    // cin.getline(name, ArSize);      // 针对字符数组, 使用 cin.getline()
    getline(cin, name);                // 针对string类, 它不需要指定大小, 所以直接用getline()就可以了, 注意, 数据来源写 cin

    cout << "Enter your favorite dessert: \n";
    // cin.getline(dessert, ArSize);   // 针对字符数组, 使用 cin.getline()
    getline(cin, dessert);             // 注意, 数据来源写 cin

    cout << "I have some delicious dessert " << dessert << " for you, " << name << ".\n";

    return 0;
}