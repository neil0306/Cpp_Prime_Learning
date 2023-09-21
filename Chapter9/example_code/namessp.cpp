#include <iostream>
#include "namesp.h"

int main(void)
{
    using debts::Debt;
    using debts::showDebt;

    Debt golf = {{"Michael", "Jordan"}, 120};
    showDebt(golf);

    return 0;
}