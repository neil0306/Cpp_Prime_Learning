#include <iostream>
#include "stock20.h"

using namespace std;
const int STKS = 4;

int main(void)
{
    Stock stocks[STKS] = {
        Stock("Nano Smart", 12, 20.0),
        Stock("Boffo", 200, 2.0),
        Stock("Mono", 130, 3.25),
        Stock("Fleep", 60, 6.5),
    }; 
    cout << "Stock holding: \n";
    int st;
    for (st = 0; st < STKS; st++){
        stocks[st].show();
        cout << "------" << endl;
    }

    const Stock *top = &stocks[0];

    for(st = 1; st < STKS; st++){
        top = &top->topval(stocks[st]);
    }
    cout << "Most valuable holding:\n";
    top->show();

    return 0;
}