#include <iostream>

int main(void)
{
    using namespace std;

    const int convert = 12;
    int height;

    cout << "Please enter you height in inches: _\b";   // \b 用来表征退格符, 把光标移动到对应的下划线上面
    cin >> height;
    cout << "Your height is " << height / convert << " feet and " << height % convert << " inches." << endl;

    return 0;
}