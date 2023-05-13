#include <iostream>

int main(void)
{
    using namespace std;
    int space = 0;
    int total = 0;
    char ch;

    cin.get(ch);        // 捕获输入
    while (ch != '.')   // 如果输入 . 则停止捕获; 注意是单引号
    {
        if (ch == ' ')
        {
            ++space;    // 这里的 ++space 和 space++ 没有区别 
        }
        ++total;        // 只要加1就行, 无论是 ++total 还是 total++
        cin.get(ch);
    }    

    cout << "Spcace = " << space << endl;
    cout << "Total characters = " <<  total << endl;

    return 0;
}