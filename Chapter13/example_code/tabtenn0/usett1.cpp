#include <iostream>

#include "tabtenn1.h"

using namespace std;

int main(void)
{
/*
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if(player1.HasTable()){
        cout << ": has a table." << endl;
    }
    else{
        cout << ": hasn't a table." << endl;
    }

    player2.Name();
    if(player2.HasTable()){
        cout << ": has a table." << endl;
    }
    else{
        cout << ": hasn't a table." << endl;
    }
*/


    // 测试派生类
    RatedPlayer rplayer1(1140, "Mallory", "Duck", false);   // 派生类创建对象
    rplayer1.Name();
    if(rplayer1.HasTable()){
        cout << ": has a table." << endl;
    }
    else{
        cout << ": hasn't a table." << endl;
    }

    rplayer1.Name();
    cout << ": rating: " <<  rplayer1.Rating() << endl;

    return 0;
}
