#include <iostream>
#include "stonewt.h"

using namespace std;

const int SIZE = 6;

int main(void)
{
    Stonewt stone_arr[SIZE] = {275, Stonewt(285.7), Stonewt(21, 8)};
    Stonewt max = stone_arr[0];
    Stonewt min = stone_arr[0];
    Stonewt eleven = Stonewt(11.0, 0.0);
    unsigned int count = 0;
    double input;

    for (int i = 3; i < SIZE; i++){
        cout << "Enter number " << i + 1 << " element.(in pounds)" << endl;
        cin >> input;
        stone_arr[i] = Stonewt(input);
    }

    for (int i = 0; i < SIZE; i++){
        max = max > stone_arr[i] ? max : stone_arr[i];
        min = min < stone_arr[i] ? min : stone_arr[i];
        if(stone_arr[i] > eleven){
            count += 1;
        }
    }

    cout << "The max weight: ";
    max.show_lbs();
    cout << "The min weight: ";
    min.show_lbs();
    cout << count <<  " objects are heavier than eleven." << endl;

    return 0;
}
