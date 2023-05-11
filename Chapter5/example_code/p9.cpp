#include <iostream>
#include <string>

using namespace std;

const string DONE = "done";

int main(void){
    string word;   // 可接收19个英文字母+1个空白字符
    int count = 0;

    cout << "Enter words (to stop, type done ): \n";

    do {
        cin >>  word;
        cin.get();     // 干掉回车
        count++;       // 在这里count++的时候, 第一次输入就是done也会变成1, 所以最后输出的时候要-1

    }while (word !=  DONE);

    cout << "You enter a total of " << count-1 << " words.\n";   // 这里要-1, 因为最后一次输入的是"done", 也被算进去了
    return 0;
}