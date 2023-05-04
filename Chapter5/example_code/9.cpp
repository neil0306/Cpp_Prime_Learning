#include <iostream>

int main(void)
{
    using namespace std;

    double num, sum = 0.0;

    cout << "Calculate five numers sum and average." << endl;
    cout << "Please input five numbers: " << endl;

    // 花括号表示循环体, 循环体里的语句是被视为一个整体的(整个循环体被当做一条语句, 所以 ++i 是在循环体执行完才自增)
    for (int i =1; i <=5; ++i){
        cout << "Value " << i << ": ";
        cin >> num;
        sum += num;
    }

    cout << "Sum = " << sum << endl;
    cout << "Average = " << sum / 5.0 << endl;

    return 0;
}