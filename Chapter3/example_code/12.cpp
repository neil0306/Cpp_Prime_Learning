#include <iostream>

int main(void)
{
    using namespace std;

    const int Lbs_per_stn = 14; // 一英石等于十四磅

    int lbs;

    cout << "Enter your weight in pounds: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;   // 多少英石
    int pounds = lbs % Lbs_per_stn;  // 剩余多少磅

    cout << lbs << " pounds = " << stone << " stone " << pounds << " pounds." << endl;
    return 0;
}
