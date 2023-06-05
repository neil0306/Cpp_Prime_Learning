#include <iostream>

using namespace std;

long double probability(unsigned int numbers, unsigned int picks);

int main(void)
{
    unsigned int total, choices;
    cout << "Enter the total number of choices on the game card and the number of picks allowed:";
    
    while (cin >> total >> choices)  // 连续输入两个数, 并同时分别按输入顺序赋值
    {
        cout << "You have one chance in ";  // 中间的概率
        cout << probability(total, choices);
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye.\n";
    return 0;
}

long double probability(unsigned int numbers, unsigned int picks)
{
    double n , p;
    long double result = 1.0;

    for (n = numbers, p = picks ; p > 0; n--, p--)
    {
        result = result * (n/p);
    }
    return result;
}



