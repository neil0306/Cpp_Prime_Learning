#include <iostream>

int main(void)
{
    using namespace std;
    
    int carrots;

    cout << "How many carrots do you have?" << endl;
    cin >> carrots;             // 用 cin 捕获用户的输入, 注意控制符的方向: 将cin捕获的值流到carrots
    cout << "Here are two more. ";
    carrots = carrots + 2;
    cout << "Now you have " << carrots << " carrots." << endl;


    //另一种写法 -- cout 语句分成多行写
    // 这是由于 cout 的自由格式规则将标记间的换行符和空格符看做是可互换的.
    cout << "Now you have "
         << carrots
         << " carrots."
         << endl;

    return 0;
}



