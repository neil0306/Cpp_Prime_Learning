#include <iostream>
#include <fstream>      // 文本IO库
#include <cstdlib>      // exit() 函数库, 这是c语言的库 <stdlib.h>, 所以前面加了c

using namespace std;

const int SIZE = 60;

int main(void) 
{  
    char filename[SIZE];
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);

    //打开文件
    ifstream inFile;            // 新建对象, 因为是要读文件, 这里要使用 ifstream, 写文件的话, 要使用 ofstream
    inFile.open(filename);      // 将对象与文件关联起来

    // 注意: 一定要判断一下文件已经打开成功
    if ( !( inFile.is_open() ) )    // 用 is_open() 方法判断是否成功打开文件
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating!" << endl;
        
        exit(EXIT_FAILURE);         // 如果程序异常退出, 一般用exit(EXIT_FAILURE)
    }
    cout << "Open the txt file successfully!\n" ;

    // 下面是读取成功后, 对读取的数据进行操作
    double value;
    double sum = 0.0;
    int count = 0;

    inFile >> value;                // inFile 对象的用法和 cin 是一样的 (所有的cin方法, 在ifstream类中都有定义!)
    cout << "Data (read from file): " << value << " ";
    // 联想 cin 中捕获的数据不匹配的情况, 这里的 inFile 同样可能发生
    while (inFile.good())          // 用 good() 方法判断文件数据是否读取顺利(包括读取之后的数据类型匹配问题)
    {
        count += 1;
        sum += value;
        inFile >> value;            // inFile 每次只读取一个数据 (value是double类型, 每次会自动读取一个浮点类型数据)
        cout << value << " ";
    }
    cout << endl;

    // 判断文件读取的退出情况: 1. 正常读完文件; 2. 遇到数据类型不匹配, 导致读取停止; 3. 未知原因导致停止.
    if (inFile.eof())               // 用 eof() 方法判断是否读到文件末尾
    {
        cout << "End of file reached! \n";
    }   
    else if (inFile.fail())         // 用 inFile.fail() 判断读取的数据类型是否与 value 不匹配, 如果不匹配, 就返回true 
    {
        cout << "Input terminated by data miss-matched! \n";
    }
    else
    {
        cout << "Input terminated by unkown reason...\n";
    }

    // 对读取的数据进行操作
    if (0 == count)
    {
        cout << "No data processed!\n";
    }
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Avg: " << sum/count << endl;
    }

    inFile.close();  // 别忘记关闭文档

    return 0;
}