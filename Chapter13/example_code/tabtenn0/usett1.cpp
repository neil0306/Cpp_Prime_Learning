#include <iostream>

#include "tabtenn1.h"

using namespace std;

int main(void)
{
    RatedPlayer rplayer1(1140, "Mallory", "Duck", false);
    TableTennisPlayer player1("Tara", "Boomdea", false);

    rplayer1.Name();
    if(rplayer1.HasTable()){
        cout << ": has a table." << endl;
    }
    else{
        cout << ": hasn't a table." << endl;
    }
    rplayer1.Name();
    cout << ": Rating: " << rplayer1.Rating() << endl;


    RatedPlayer rplayer2(1212, player1);        // 使用自定义的第二个构造函数
    cout << "Name: ";
    rplayer2.Name();     // 基类的成员函数
    cout << ", Rating: " << rplayer2.Rating() << endl;

    return 0;
}
