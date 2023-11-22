#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

vector<int> lotto(int ndot, int rdot );

int main(void)
{
    vector<int> winners;
    winners = lotto(51, 6);
    vector<int>::iterator pd;
    for (pd = winners.begin(); pd != winners.end(); pd++){
        cout << *pd << " ";
    }
    cout << endl;
    return 0;
}

vector<int> lotto(int ndot, int rdot )
{
    vector<int> temp;
    srand(time(0));     // 设置随机种子
    for (int i = 0; i < rdot; i++){
        temp.push_back(rand() % ndot);
    }
    return temp;
}