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

    // 測試遙控器的狀態
    cout << "-----------\n";
    cout << "Remote Mode = " << rt.show_remote_mode() << endl;
    Panda.set_remote_mode(rt);
    cout << "After Change Mode, Remote Mode = " << rt.show_remote_mode() << endl;

    cout << "---------" << endl;
    rt.onoff(Panda);
    Panda.showSettings();
    return 0;
}