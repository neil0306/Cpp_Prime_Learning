#include "p6.h"
#include <iostream>

using namespace std;

int main(void)
{
    Move m1(11.1, 22.2);
    Move m2(10.0, 20.0);
    double x, y;
    m1.showmove();
    m2.showmove();

    cout << "Enter new x and y: ";
    cin >> x >> y;
    m1.reset(x, y);
    m1.showmove();

    Move m3 = m1.add(m2);
    cout << "Show m3..." << endl;
    m3.showmove();
    return 0;
}
