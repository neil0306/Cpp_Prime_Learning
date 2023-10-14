#include <iostream>
#include "stonewt.h"

using namespace std;

int main(void)
{
    // 下面这行代码将触发 "类的自动类型转换"
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    incognito.Set_type(Stonewt::POUNDS);
    cout << incognito;

    wolfe.Set_type(Stonewt::FLOATPOUNDS);
    cout << wolfe;

    taft.Set_type(Stonewt::STONE);
    cout << taft;

    cout << "-------- testing operator ------" << endl;
    taft = incognito + wolfe;
    taft.Set_type(Stonewt::STONE);
    cout << "taft = " << taft;

    taft = wolfe - incognito;
    taft.Set_type(Stonewt::FLOATPOUNDS);
    cout << "taft = " << taft;

    incognito = incognito * 2;
    incognito.Set_type(Stonewt::POUNDS);
    cout << "incognito = " << incognito;
    return 0;
}
