# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>          // 为了使用 EXIT_FAILUE 函数

using namespace std;


int main(void)
{   
    ifstream inFile;    // ftream 都需要自己手动创建对象    
    string fileName;
    char ch;
    int count = 0;

    cout << "Enter the file name: ";
    getline(cin, fileName);   // getline 语法: getline(输入流, 字符串对象);  cin.getline(字符数组, 数组长度);

    inFile.open(fileName); // 打开文件 (关联文件)
    if (!inFile.is_open())  // 不成功时
    {
        cout << "Failed to open file!";
        exit(EXIT_FAILURE);
    }

    while (!inFile.eof()) // 没到末尾才继续循环
    {
        inFile >> ch; // 读取文件, 逐个字符读取
        count++;
    }
    cout << fileName << " has " << count << " characters." << endl;
    inFile.close();
    return 0;
}

