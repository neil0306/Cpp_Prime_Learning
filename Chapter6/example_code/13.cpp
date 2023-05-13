#include <iostream>

using namespace std;

int main(void)
{
    int num1, num2;

    cout << "First number: ";
    cin >> num1;

    /* debug case: 
    用一个死循环来验证输入不匹配 num1 的类型时, cin是否还能工作
    while (cin.get() != '\n'); 
        
    验证结果是: 
        输入xyz之后, 再怎么输入, 程序都不会有任何反应
    解释: 
        输入的 xyz 不是 int 类型, 导致 cin 对象直接设置了一个错误标记位, 此时cin不再工作, 程序将一直停在 while 语句这里.
    */


    /*
    解决上面 debug case 的问题:
        cin.clear()                   // 重置 cin对象的 错误标志位
        while (cin.get() != '\n');    
    
    解释:
        1) 输入 xyz, 按下回车之后, 读进来的 xyz 触发类型不匹配, 导致cin停用;
        2) cin.clear() 语句直接把 cin 功能复位了;
        3) 由于使用的是 cin >> num1, 此时输入缓冲区 还有个 \n, 这个回车被 while 里面的 cin.get() 读出来了, 并且 判断条件返回一个 false, 直接跳出 while 循环;
        4) 接下来就可以正常输入 num2 了.
    */
    

    cout << "Last number: ";
    cin >> num2; 

    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    
    return 0;
}

/*
代码运行效果: 

1) 输入正确数字:
    First number: 5 
    Last number: 9
    num1 = 5, num2 = 9

2) 输入字母xyz:
    First number: xyz
    Last number: num1 = 0, num2 = 1          

说明:
    输入xyz后, 发生类型不匹配, cin 返回了 false, 同时cin对象中有个错误标记被设置, 
    cin 功能将停止运行, 所以 num2 将不允许输入. 
*/