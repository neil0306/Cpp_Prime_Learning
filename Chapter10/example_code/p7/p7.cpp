#include "p7.h"

plorg::plorg(const char str[], int ci)
{
    strcpy(name, str);
    CI = ci;
}

void plorg::reset(int ci)
{
    CI = ci;
}

void plorg::show() const
{
    cout << "Name: " << name << endl;
    cout << "CI: " << CI << endl;
}

