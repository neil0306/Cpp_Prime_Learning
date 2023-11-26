#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    ifstream fin1;
    ifstream fin2;
    ofstream fout;

    fin1.open("t1.dat");
    fin2.open("t2.dat");
    fout.open("t3.dat");

    string str;
    while(!fin1.eof() || !fin2.eof()){
        // 拷贝第一个文件
        if (getline(fin1, str) && str.size() > 0){
            fout << str;
        }

        // 拷贝第二个文件
        fout << " ";
        if (getline(fin2, str) && str.size() > 0){
            fout << str;
        }
        fout << endl;
    }
    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}
