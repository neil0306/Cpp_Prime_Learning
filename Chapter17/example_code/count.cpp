#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])      // 如果在终端中需要输入参数, 则这里需要给main函数添加参数列表
/*
    main函数的参数列表:
        int argc: 表示有多少个参数
        *argcv[]: 字符串指针数组
                    在执行时, argv 的第一个参数一般是当前程序的文件名

*/
{
    if(argc == 1)       // 此时运行程序时没有给任何参数, 终端中只输入的程序名称, 如: ./a.out
    {
        cout << "Usage: " << argv[0] << " filenames(s)" << endl;
        exit(0);
    }

    long count = 0;
    long total = 0;
    char ch;

    ifstream fin;
    for (int i = 1; i < argc; i++){  // i = 1时, argv[i] 对应的字符串才是参数
        fin.open(argv[i]);
        if(!fin.is_open()){
            cout << "Cannot open " << argv[i] << endl;
            fin.clear();
            continue;
        }
        count = 0;
        while(fin.get(ch)){
            count++;
        }
        cout << count << " characters in " << argv[i] << endl;
        total += count;
        fin.clear();
        fin.close();
    }

    cout << total << " characters in all files." << endl;

    return 0;
}
