#include <iostream>
#include <fstream>
#include <cstdlib>      // 使用 EOF

using namespace std;

int main(int argc, char * argv[])       // 为了接收终端参数, 第二个参数得是指针数组
{
    char ch;
    ofstream fout;      // 要写入文件, 需要用 ofstream 对象

    if(argc < 2){
        cout << "Usage: filename val1 val2" << endl;
        exit(0);
    }

    fout.open(argv[1]);
    if (fout.is_open()){
        cout << "Please enter the data: ";
        while (cin.get(ch) && ch != EOF )
        {
            fout << ch;     // 将输入的内容写入文件
        }
    }
    else{
        cout << "Cannot open/create the file " << argv[1] << endl; 
    }
    return 0;
}