#include <iostream>

using namespace std;

int main(void)
{
    int cnt = 0;
    char ch;

    cout << "Enter a string: ";
    while(cin.peek() != '$')            // 检查字符, 不是 $ 就继续从输入缓冲区中读取
    {
        cin.get(ch);
        cnt++;
    }
    cout << "count = " << cnt << endl;

    return 0;
}
