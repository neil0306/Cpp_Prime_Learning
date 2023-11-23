#include <iostream>
#include <fstream>      // 有些系统/编译器 在  fstream 中会包含 iostream
#include <string>

using namespace std;

int main(void)
{
    string filename;
    cout << "Enter name for new file: ";
    cin >> filename;

    ofstream fout;                          // ostream 对应 cout
    fout.open(filename);                    // 如果没有这个文件, 就创建&打开
    /*
        用默认的方式 open 时, 如果文件已经存在, 则会清空文件中原有内容
    */
    fout << "For your eyes only!" << endl;  // 往文件中写入内容
    cout << "Enter your secret number: " << endl;
    float secret;
    cin >> secret;
    fout << "Your secret number is: " << secret << endl;
    fout.close();

    ifstream fin;
    fin.open(filename);
    cout << "Here are the contents of " << filename << ": " << endl;
    char ch;
    while(fin.get(ch)){
        cout << ch;
    }
    cout << endl;
    fin.close();

    return 0;
}