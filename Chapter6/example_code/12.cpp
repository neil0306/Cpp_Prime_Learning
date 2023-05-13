#include <iostream>
#include <string>
#include <cctype>       // 调用判断空格的函数

using namespace std;

int main(void)
{
    string line;
    int spaces = 0;

    cout << "Enter a line of text: ";
    getline(cin, line);
    cout << "Complete line: " << line << endl;

    for (int i = 0; line[i] != '\0'; i++ )   // 注意这里的 i 的条件
    {
        cout << line[i];
        if (line[i] == '.')         // 遇到句号就不再回显后面的字符
            break;
        
        // 写法1:
        // if (isspace(line[i]))
        //     spaces += 1;
        // else
        //     continue;

        // 写法2:
        if (line[i] != ' ')
            continue;           // 如果执行 continue, 将跳到 for 的 i++ 位置, 然后走到 "line[i] != '\0'", 之后回到循环体中.
        spaces += 1;
    }
    cout << endl;
    cout << "Spaces = " << spaces << endl;
    return 0;
}