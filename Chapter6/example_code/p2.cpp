#include <iostream>
#include <array>

using namespace std;

const int Max = 10;

int main(void)
{  
    array<double, Max> donation;
    double input;
    int count = 0;
    double sum = 0.0;
    double average = 0;

    cout << "Please enter the double numerial: ";
    
    while ( cin >> input)   // 用 input 存放输入的数字, cin 判断是否读入正确
    {
        donation[count++] += input;             // count++ 将在赋值完成后自增1
        if (count == 10)
            break;
        cout << "Please enter the double numerial: ";
    }
    
    for (int i = 0; i < count; i++)
        sum += donation[i];
    
    average = sum / count;
    
    int bigger = 0;
    for (int i = 0; i < count; i++)
    {
        if (donation[i] > bigger)
            bigger++;
    }

    cout << "Avg = " << average << ", " << bigger << " bigger numbers are biggder than average.\n"; 

    return 0;
}