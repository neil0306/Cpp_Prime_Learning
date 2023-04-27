#include <iostream>

int main(void)
{
    using namespace std;
    const int ArSize = 20;

    char name[ArSize];
    char dessert[ArSize];

    //观察程序的bug 
    cout << "Enter you name: \n";

    /* 为了解决 cin 读取字符的问题, 下面改用cin的成员函数 get()  */
    cin.get(name, ArSize);              // 输入 Alistair Dreeb, 此时是整行进行读取, 要么识别到回车键停止捕获, 
                                            // 要么是输入达到最大字符数量进行截断, 这里是 ArSize-1, 
                                            // 超过ArSize-1的部分仍然会保存在系统缓存里, 不会让我们输入字符给 dessert, 但是dessert也不会去读取缓存里的内容

    // 解决办法: 用get(), 注意是不带参数的get(). 用它去清空缓冲区中的 "一个元素", 如果读取的刚好是"换行符", 那么下一次cin读取的时候就可以重新读取键入的内容 
    // get() 如果读取字符后(注意只会读取1个字符), 缓冲区中仍然存在字符, 那么这个bug依然会存在, 此时下面的 dessert 也是不会让用户输入的 
    cin.get();                          // 也可以把它拼接到上面的cin语句中, 直接写为 cin.get(name, ArSize).get();

    // cout << "我直接输出cin.get(), 读出来的是: " << cin.get();   // 用来测试 get() 到底读取了多少个字符, 答案是1个字符

    cout << "Enter your favorite dessert: \n";
    cin.get(dessert, ArSize);           // 当触发上述bug时, 这里不会给我们输入字符的机会, 直接跑到下面的cout

    cout << "I have some delicious dessert " << dessert << " for you, " << name << ".\n";

    return 0;
}