#include <iostream>
#include "golf.h"

using namespace std;

int main(void)
{
    golf p1("Rick", 100);  // 自定义构造
    golf p2;                // 默认构造

    cout << endl;
    cout << "Now Show Two person...\n";

    p1. showgolf();
    cout << "-------" << endl;
    p2.showgolf();
    return 0;
}
