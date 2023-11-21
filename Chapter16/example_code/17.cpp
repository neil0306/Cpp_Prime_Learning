#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    string letters;
    cout << "Enter the letter group (enter quit to quit): ";
    while(cin >> letters && letters != "quit"){
        cout << "Permutetation: " << endl;
        // 为了能输出所有排列组合, 先进行一次sort排序
        sort(letters.begin(), letters.end());
        while(next_permutation(letters.begin(), letters.end())){     // 使用 STL 算法进行排列组合: 它是按照字母递增的顺序判断是否还能进行排序的, 只要还能进行重新排序, 就会返回 true; 当字母已经按照倒序排序时, 将不会进行排列组合.
            cout << letters << endl;
        }
        cout << "Enter the next letter group (enter quit to quit): ";
    }
    return 0;
}