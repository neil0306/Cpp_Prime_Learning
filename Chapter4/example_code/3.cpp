#include <iostream>

int main(void)
{
    using namespace std;
    const int ArSize = 20;

    char name[ArSize];
    char dessert[ArSize];

    //观察程序的bug 
    cout << "Enter you name: \n";

    /* 下面的 cin 会触发 bug: 当键盘输入的文字包含 "空格, 回车" 等空白字符时, 就认为第一个字符串结束了, 
        剩下的输入会保存到系统的缓冲区中, 当下一次调用cin的时候, cin 不会马上接收键盘输入, 而是先检查系统缓冲区, 
        如果缓冲区还有内容, 就会直接读取缓冲区的数据给到当前的cin. */
    cin >> name;              // 输入 Alistair Dreeb, 此时Alistair 直接被赋值给name, 剩下的 Dreeb 会直接在下面的cin语句赋值给dessert


    cout << "Enter your favorite dessert: \n";
    cin >> dessert;           // 当触发上述bug时, 这里不会给我们输入字符的机会, 直接跑到下面的cout

    cout << "I have some delicious dessert " << dessert << " for you, " << name << ".\n";

    return 0;
}