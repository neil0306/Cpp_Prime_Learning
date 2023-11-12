#include <iostream>

#include "tv.h"

using namespace std;

int main(void)
{
    Tv Panda;
    cout << "Initial Settings for Panda TV: " << endl;
    Panda.showSettings();

    Panda.onoff();
    Panda.showSettings();

    cout << "---------" << endl;
    Panda.volup();
    Panda.chanup();
    Panda.showSettings();

    // 定義遙控器對象(友元類對象), 然後控制電視機
    Remote rt;
    cout << "---------" << endl;
    rt.setChannel(Panda, 88);
    rt.volup(Panda);
    rt.volup(Panda);
    Panda.showSettings();

    cout << "---------" << endl;
    rt.onoff(Panda);
    Panda.showSettings();
    return 0;
}