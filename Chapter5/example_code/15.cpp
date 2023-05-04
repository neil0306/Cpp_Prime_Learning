#include <iostream>

const int ArrSize = 20;

using namespace std;

int main(void)
{
    char name[ArrSize];

    cout << "Your first name, please: ";
    cin >> name;

    int i = 0;
    cout << "Here is your name, verticalized and ASCIIized: \n";
    while (name[i] != '\0')     // 字符串结束符是 '\0', 这是默认加入的字符
    // while (name[i])            // 上面的 while 还可以写成 while (name[i]), 因为空字符 \0 在判断语句中的返回值是0
    {
        cout << name[i] << ": " << int(name[i]) << endl;    // int(name[i]) 将字符转换为对应的 ASCII 码
        i++;
    }

    

    return 0;

}