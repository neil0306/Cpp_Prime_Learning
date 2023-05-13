#include <iostream>

using namespace std;
const int Max = 5;

int main(void)
{
    int golf[Max];

    cout << "Please input your golf scores.\n";
    cout << "Your must enter " << Max << " rounds' scores.\n";

    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "Round #" << i+1 << ": "; 
        // 判断输入的类型是否匹配
        while ( !(cin >> golf[i]) ) // 如果输入成功, golf 直接被赋值, cin返回 true, 否则cin 返回false, golf[i] 没有被赋值
        {
            cin.clear();
            while (cin.get() != '\n');   // 不断把输入缓存的东西读取出来, 直到读取到 换行, 也就是清空掉所有输入
            
            cout << "You should enter number! Please enter again: ";
        }
    }

    double total = 0.0;
    for (int j = 0; j < Max; j++)
    {
        total += golf[j];
    }

    cout << "total score = " << total << endl;

    cout << "Avg score = " << total / Max << endl;


    return 0;
}