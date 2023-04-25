#include <iostream>
using namespace std;

int main(void)
{
    char ch;
    cout << "Enter a character: ";
    cin >> ch;   //cin将字符型变量转换成对应的ASCII码 (根据变量类型来识别是否转ASCII码并完成转换), 内存中存储的是ASCII码

    // cout 根据变量类型, 将ASCII码转换成对应的字符进行输出
    cout << "Hello, thank you for entering the character " << ch << endl;
    
    return 0;
}