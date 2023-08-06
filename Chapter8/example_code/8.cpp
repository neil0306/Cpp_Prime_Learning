/*
    当物镜焦距一定时, 计算不同目镜焦距下的放大倍数.
*/
#include <iostream>
#include <fstream>

using namespace std;
const int LIMIT = 5;
void file_it(ostream &OS, double fo, const double fe[], int n);

int main(void)
{
    fstream fout;
    const char *fn = "ep-data.txt";

    fout.open(fn);
    if(!fout.is_open()){        // 打开失败
        cout << "Can't open " << fn << ".Bye" << endl;
        exit(EXIT_FAILURE);     // 直接结束程序
    }

    double objective;       // 物镜的焦距
    cout << "Enter the focal length of telescope objective in mm:" << endl;
    cin >> objective;

    double eps[LIMIT];      // 目镜的焦距(数组)
    for (int i = 0; i < LIMIT; i++){
        cout << "EyePieces #" << i+1 << endl;
        cin >> eps[i];
    }

    file_it(cout, objective, eps, LIMIT);      // 在终端中显示结果
    file_it(fout, objective, eps, LIMIT);      // 在文件中记录结果

    cout << "Done!" << endl;
    return 0;
}

/* 
形参的定义中使用到知识点: 
    1. 基类对象的引用既可以"指向基类对象", 也可以指向"派生类对象"
    2. 数组可以使用数组表示法, 也可以使用指针表示法(本质上两种都是在传递指针)
*/
void file_it(ostream &OS, double fo, const double fe[], int n)
{
    // OS 是基类对象的引用, 通过传入对象的不同可以实现不同的执行效果
    OS << "Focal Length of objective: " << fo << endl;
    OS << "f.1. eyepieces " << "magnification" << endl;
    for (int i = 0; i < LIMIT; i++){
        OS << "\t" << fe[i] << "\t" << static_cast<int>(fo/fe[i] + 0.5) << endl;
    }
}