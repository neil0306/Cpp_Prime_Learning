#include <iostream>
#include <string>

int main(void){
    using namespace std;

    string word = "?ate";

    for(char ch = 'a'; word != "mate"; ch++)   // 直接使用 != 运算符, 无需使用 strcmp 函数
    {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop, word = " << word << endl;
    return 0;
}
