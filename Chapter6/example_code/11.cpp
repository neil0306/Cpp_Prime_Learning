// 使用枚举量作为 Switch 的整型表达式
#include <iostream>

using namespace std;

enum {red, orange, yellow, green, blue, violet, indigo};

int main(void)
{
    int code;
    cout << "Enter color code (0~6): ";
    cin >> code;

    while (code >= red && code <= indigo)
    {   
        switch (code)
        {
            case red : cout << "You choose red! \n"; break;
            case orange : cout << "You choose orange! \n"; break;
            case yellow : cout << "You choose yellow! \n"; break;
            case green : cout << "You choose grenn! \n"; break;
            case blue : cout << "You choose blue! \n"; break;
            case violet : cout << "You choose violet! \n"; break;
            case indigo : cout << "You choose indigo! \n"; break;
        }

        cout << "Enter color code (0~6): ";
        cin >> code;
    }

    cout << "Bye!" << endl;

    return 0;
}