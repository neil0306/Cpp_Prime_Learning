#include <iostream>
using namespace std;
const int ArrSize = 6;

int main(void)
{
    float value[ArrSize], temp;
    int i = 0;          // 统计输入次数

    cout << "Enter 6 numbers and compare with your level. \n";
    cout << "Terminate condition, when you make 6 number or enter a negative number. \n";

    cout << "Enter the 1st value: ";
    cin >> temp;

    while (0  <= temp && i < ArrSize)
    {
        value[i] = temp;
        ++i;
        if (i < ArrSize)
        {
            cout << "Next value: ";
            cin >> temp;
        }
    }

    if (0 == i)
        cout << "No data -- bye!\n";
    else                                // 数组中存放了有效的数字, 开始统计
    {
        cout << "Enter your level: ";
        float level;
        cin >> level;
        int count = 0;
        for (int j = 0; j < i; ++j)
        {
            if(value[j] > level)
                count +=1;
        }
        cout << count << " of your scores are higher than your level.\n";
    }

    return 0;
}