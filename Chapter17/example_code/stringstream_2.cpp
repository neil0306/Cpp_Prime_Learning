/*
    测试 stringstream, 把 record 文件里写入的 1~10 进行求和.
        注: 文件中的数字是字符, 首先要转成数字, 才能进一步求和.
*/

#include <iostream>
#include <fstream>      // 有些系统/编译器 在  fstream 中会包含 iostream
#include <string>
#include <sstream>      // 使用 stringstream 需要引入这个头文件

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
    int n = 0;
    stringstream ss;       // stringstream 的用法与 iostream 类似

    // 将捕获到的字符一个个存入 stringstream 对象中
    while(fin.get(ch)){
        ss << ch;         // 将读出来的字符放入 stringstream
    }

    // 把字符串格式化为数字, 存入n中
    while(ss >> n){
        sum += n;
    }
    cout << "sum = " << sum << endl;
    fin.close();
    return 0;
}