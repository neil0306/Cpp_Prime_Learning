#include <iostream>
#include "emp.h"

using namespace std;

int main(void) 
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;

    fink fi("Matt", "Oggs", "Oiler", "Junobarr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");
    hf.ShowAll();

    cout << "Press a key for next phase:" << endl;
    cin.get();	
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer: " << endl;
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i] -> ShowAll();
    return 0;
}
