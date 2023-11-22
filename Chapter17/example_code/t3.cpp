#include <iostream>

using namespace std;

int main(void)
{
    char ch;
    int ct = 0;

    // cin >> ch;   // 捕获的内容直接存入ch
    ch = cin.get();
    while(ch != '\n'){
        cout << ch;
        ct++;
        // cin >> ch; 
        ch = cin.get();
    }
    cout << endl;
    cout << "ct = " << ct << endl;
    return 0;
}