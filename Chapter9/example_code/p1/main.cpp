#include <iostream>
#include "golf.h"

using namespace std;

const int SIZE = 3;

int main(void)
{
    golf g[SIZE];      // 2个数组
    int count = 0;     // 统计输入的次数

    cout << "Please enter the infomation of golf players: " << endl;

    while( count < SIZE && setgolf(g[count]) ){
        cout << "Please enter next player: " << endl;
        count ++;
    }

    cout << "\nShowing all golg infomations..." << endl;

    for(int i = 0; i < count; i++){
        showgolf(g[i]);
    }

    cout << "Reset all the player's information..." << endl;

    for (int i  = 0; i < count; i++){
        handicap(g[i], 90);
        showgolf(g[i]);
    }
    return 0;

}
