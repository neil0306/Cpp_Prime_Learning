#include <iostream>

int main(void)
{   
    using namespace std;

    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";  
    // cin >> ch;
    cin.get(ch);   // 为了捕获空字符, 使用cin.get()代替cin >> ch

    // while (ch != '#')
    while (cin.eof() == false)   // 没到文件尾时, cin.fail()返回false
    {
        cout << ch;
        ++count;
        // cin >> ch;
        cin.get(ch);   // 为了捕获空字符, 使用cin.get()代替cin >> ch

    }
    cout << endl;
    cout << count << " characters read\n";

    return 0;
}