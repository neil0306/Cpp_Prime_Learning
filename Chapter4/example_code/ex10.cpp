#include <iostream>
#include <array>

using namespace std;

int main(void)
{
    const int N = 3;

    array<double,N> grade1;         // 用array 模板创建一个数组

    cout << "please enter your 1st grade of 40 yards: ";
    cin >> grade1[0];

    cout << "please enter your 2nd grade of 40 yards: ";
    cin >> grade1[1];

    cout << "please enter your 3rd grade of 40 yards: ";
    cin >> grade1[2];


    cout << "You had run "<< N << " times. The average grade is: " << (grade1[0] + grade1[1] + grade1[2])/3.0 << endl;
    return 0;
}