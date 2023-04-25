#include <iostream>

int main(void)
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;     // double -> float
    
    //以下两行在编译时会有warning, 但没有error
    int guess(3.9832);  // double -> int, 没越界, 小数部分丢弃
    int debt = 7.2E12;  // double -> int, 已经超出int范围(越界), 得到的结果是不可预计的

    cout << "tree = " << tree << endl;   // mac 下打印出来是3.000000
    cout << "guess = " << guess << endl; // mac 下打印出来是3
    cout << "debt = " << debt << endl;   // mac 下打印出来是1

    return 0;
}