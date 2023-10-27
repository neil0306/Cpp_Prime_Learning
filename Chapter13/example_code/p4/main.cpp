#include "bop.h"
#include <iostream>

using namespace std;

int main(void)
{
    Port port1("ABC", "sweet", 200);
    cout << port1 << endl;
    cout << "-----------" << endl;

    VintagePort vp("EFG", "vintage", 300, "old Jack", 40);
    cout << vp << endl;
    cout << "-----------" << endl;

    VintagePort vp2(vp);
    cout << vp2 << endl;
    cout << "-----------" << endl;

    Port * p_port;
    p_port = &port1;
    p_port->Show();     // 基类show
    cout << "-----------" << endl;

    p_port = &vp;
    p_port->Show();     // 派生类show
    cout << "-----------" << endl;

    return 0;
}