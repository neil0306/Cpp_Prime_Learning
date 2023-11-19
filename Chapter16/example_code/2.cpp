#include <iostream>
#include <fstream>      // 在第十七章詳細講解
#include <string>
#include <cstdlib>      // 用到了 EXIT_FAILURE

using namespace std;

int main(void)
{
    ifstream fin;

    fin.open("abc.txt");

    if(fin.is_open() == false){
        cerr  << "Can't open flie. Bye. ";   // cerr 只能輸出到標準輸出設備上(cout則還可以輸出到比如文本等其他位置上)
        exit(EXIT_FAILURE);
    }

    string item;
    int count = 0;
    getline(fin, item, ':');        // 從fin中讀取內容, 讀取的內容放到 item 中, 但遇到指定的 ':' 字符時停止讀取(不包含指定的字符)
    while(fin){
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':'); 
    }

    fin.close();


    return 0;
}

