#include <iostream>
#include <cstring>

using namespace std;
const int SIZE = 30;
struct CandyBar
{
    char brand[SIZE];
    double weight;
    int heat;
};

void setValue(CandyBar & candybar, const char * str = "Millennium Munch", const double w = 2.85, const int h = 350);

void show(const CandyBar & bar);

int main(void)
{
    CandyBar bar;
    setValue(bar);
    show(bar);
    return 0;
}

void setValue(CandyBar & candybar, const char * str, const double w, const int h)
{
    strcpy(candybar.brand, str);
    candybar.weight = w;
    candybar.heat = h;
}

void show(const CandyBar & bar)
{
    cout << "Brand: " << bar.brand << endl;
    cout << "Weight: " << bar.weight << endl;
    cout << "Heat: " << bar.heat << endl;
}