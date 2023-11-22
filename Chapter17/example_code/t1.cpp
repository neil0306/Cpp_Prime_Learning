#include <iostream>

using namespace std;

int main(void)
{
    char ch;
    int ct = 0;

    cin.get(ch);   // 捕获的内容直接存入ch
    while(ch != '\n'){
        cout << ch;
        ct++;
        cin.get(ch); 
    }
    cout << endl;
    cout << "ct = " << ct << endl;
    return 0;
}