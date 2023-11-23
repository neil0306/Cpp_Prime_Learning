/*
    测试 stringstream, 把 record 文件里写入的 1~10 进行求和.
        注: 文件中的数字是字符, 首先要转成数字, 才能进一步求和.
*/

#include <iostream>
#include <fstream>      // 有些系统/编译器 在  fstream 中会包含 iostream
#include <string>

using namespace std;

int main(void)
{
    string filename;
    cout << "Enter name for new file: ";
    cin >> filename;

    ifstream fin;
    fin.open(filename);
    cout << "Here are the contents of " << filename << ": " << endl;

    char ch;
    int sum = 0;

    while(fin.get(ch)){
        sum += ch;
    }
    cout << "sum = " << sum << endl;
    fin.close();

    return 0;
}