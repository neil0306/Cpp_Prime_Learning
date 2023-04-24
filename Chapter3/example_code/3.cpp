#include <iostream>

int main(void)
{
    using namespace std;

    int cheat = 42;
    int waist = 0x42;
    int inseam = 042;

    // cout 默认 以 十进制 打印数字
    cout << "cheat = " << cheat << " (42 in dec)." << endl;
    cout << "waist = " << waist << " (0x42 in hex)." << endl;
    cout << "inseam = " << inseam << " (042 in oct)." << endl;
    cout << endl;

    // 都用 十六进制 打印数字
    cout << hex;
    cout << "cheat = " << cheat << " (42 in dec)." << endl;
    cout << "waist = " << waist << " (0x42 in hex)." << endl;
    cout << "inseam = " << inseam << " (042 in oct)." << endl;
    cout << endl;


    // 都用 八进制 打印数字
    cout << oct;
    cout << "cheat = " << cheat << " (42 in dec)." << endl;
    cout << "waist = " << waist << " (0x42 in hex)." << endl;
    cout << "inseam = " << inseam << " (042 in oct)." << endl;
    cout << endl;

    cout << dec;
    cout << "cheat = " << cheat << " (in dec)." << endl;
    cout << hex;
    cout << "waist = " << waist << " (in hex)." << endl;
    cout << oct;
    cout << "inseam = " << inseam << " (in oct)." << endl;


    return 0;
}