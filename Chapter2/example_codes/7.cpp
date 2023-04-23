#include <iostream>

int stonetolb(int sts);  // 函数声明

int main(void)
{
    using namespace std;

    int stone;
    cout << "Enter the weight in stones: ";
    cin >> stone;

    int pounts = stonetolb(stone);
    
    cout << stone << " stones = "
         << pounts
         << endl;
    
    return 0;
}

int stonetolb(int sts)          // 函数头
{                               // 函数体

    // 写法一:
    // int pounts;
    // pounts = 14 * sts;
    // return pounts;              // 有返回值

    // 写法二:
    return 14 * sts;
}