#include <iostream>

int main(void)
{
    using namespace std;
    long w;
    long us;

    cout << "Enter the world's population: ";
    cin >> w;
    cout << "Enter the population of the US: ";
    cin >> us;

    cout << "The population of the US is "<< (double) us / w * 100 << "% of the world population." << endl;
    // cout << "The population of the US is " << double(us) / w * 100 << "% of the world population." << endl;

    return 0;
}