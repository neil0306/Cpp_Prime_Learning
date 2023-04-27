#include <iostream>

int main(void)
{
    using namespace std;
    const int ArSize = 20;

    char name[ArSize];
    char dessert[ArSize];

    //观察程序的bug 
    cout << "Enter you name: \n";

    /* 为了解决 cin 读取字符的问题, 下面改用cin的成员函数 getline()  */
    cin.getline(name, ArSize);              // 输入 Alistair Dreeb, 此时是整行进行读取, 要么识别到回车键停止捕获, 
                                            // 要么是输入达到最大字符数量进行截断, 这里是 ArSize-1, 
                                            // 超过ArSize-1的部分仍然会保存在系统缓存里, 不会让我们输入字符给 dessert, 但是dessert也不会去读取缓存里的内容

    cout << "Enter your favorite dessert: \n";
    cin.getline(dessert, ArSize);           // 当触发上述bug时, 这里不会给我们输入字符的机会, 直接跑到下面的cout

    cout << "I have some delicious dessert " << dessert << " for you, " << name << ".\n";

    return 0;
}