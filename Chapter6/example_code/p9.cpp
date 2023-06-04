#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct patrons
{
    string name;
    double donation;
};


int main(void)
{
    ifstream inFile;   // 创建文件对象
    string fileName;

    int numbers;
    int i;          // 控制访问的结构体元素 
    bool emp_flag = true;

    cout << "Enter the file name: ";
    getline(cin, fileName);

    inFile.open(fileName);      // 文件对象关联到文件

    if(!inFile.is_open())       // 打开失败时打印log
    {
        cout << "Fail to open the file!";
        exit(EXIT_FAILURE);
    }

    patrons* ppatrons = new patrons [numbers];  // 动态结构体数组

    inFile >> numbers;  // 输入格式已经决定了第一行读取到的是一个数字, 表示捐款人数
    if(numbers <= 0)
    {
        exit(EXIT_FAILURE);
    }
    inFile.get();   // 读取换行符 (消耗掉)

    while ((!inFile.eof()) && (i < numbers))
    {
        getline(inFile, ppatrons[i].name); // 第一行
        cout << "Read name: " << ppatrons[i].name << endl;
        inFile >> ppatrons[i].donation;  // 因为读取的是double数字, 所以不应该使用getline
        cout << "Doantions: " << ppatrons[i].donation << endl;
        i++;
        inFile.get();   // 读取换行符 (消耗掉)
    }


    cout << "\n----- Grand Patrons -----\n";
    for (int i = 0; i < numbers; i++)
    {
        if (ppatrons[i].donation >= 10000)
        {
            emp_flag = false;       // 数组中有记录, 非空
            cout << ppatrons[i].name << ": " << ppatrons[i].donation << endl;
        }
    }
    if (emp_flag)
        cout << "None" << endl;   // 如果没有这类�?, 就直接打�? none

    emp_flag = true;   // re-init
    cout << "\n----- Patrons -----\n";
    for (int i = 0; i < numbers; i++)
    {
        if (ppatrons[i].donation < 10000)
        {
            emp_flag = false; 
            cout << ppatrons[i].name << ": " << ppatrons[i].donation << endl;
        }
    }

    if (emp_flag)
        cout << "None" << endl;   // 如果没有这类�?, 就直接打�? none

    return 0;
}
