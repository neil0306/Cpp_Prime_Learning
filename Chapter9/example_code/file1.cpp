#include <iostream>
#include "coordin.h"

using namespace std;

int main(void)
{
    rect rplace;
    polar pplace;
    cout << "Please the x and y values: ";

    while(cin >> rplace.x  >> rplace.y)  // 连续输入
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);

        cout << "Next two nums (q to quit): ";
    }

    return 0;
}
