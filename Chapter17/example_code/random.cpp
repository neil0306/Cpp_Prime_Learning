#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>      // 用来限制打印的数字精度, setprecision, cout << fixed;

using namespace std;

struct planet
{
    char name[20];
    double population;
    double g;
};  

int main(void)
{
    planet pl;

    const char * file = "planet.dat";  
    fstream finout;         // fstream 对象既可以读文件, 也可以写文件

    cout << fixed;          // 这行语句用来设置 "不使用科学计数法打印数字"

    // ------- 首次尝试显示二进制文件中的内容(此时二进制文件还没创建) -------
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);   // 这里指定的是只读的方式打开(ios_base::in), 如果没有这个文件, 由于是 istream, 这里不会创建这个文件!
    int ct = 0;
    if(finout.is_open()){
        cout << "Here are the current contents of the " << file << endl;
        while(finout.read((char *) &pl, sizeof pl)){      // 二进制文件的读取方式: .read((char *) &对象, sizeof 对象)
            cout << ct++ << ": " <<  pl.name << ": " << setprecision(1) << pl.population << ", " << pl.g << endl; // ct++ 表示执行完这行代码之后自增1 
        }
        if (finout.eof()){       // eof() 方法用于判断是否读到文件的末尾, 如果返回true, 此时 finout对象 内部会设置一个 eofbit 标志位, 这时候 finout 在没有使用 clear() 重置状态之前将 无法再次读写该文件!!
            finout.clear();      // 由于后面还要再操作文件, 所以先重置一下 eofbit  
        }
    }

    cout << "Enter the record number you wish to change: ";
    int rec;
    cin >> rec;
    while(cin.get() != '\n');       // 数字和字符串交替输入时, 勿忘清除回车!!!

    // 判断是否越界
    if(rec < 0 || rec >= ct){
        cout << "Out of range!" << endl;
        exit(0);
    }

    streampos place = rec * sizeof pl;   // 计算准备修改的位置
    // 读文件时, 定位指针用 seekg()
    finout.seekg(place);                  // 用 seekg() 方法先定位一下文件指针, 方便读取文件里的内容
    finout.read((char *) &pl, sizeof pl);
    cout << rec << ": " << pl.name << ": " << setprecision(1) << pl.population << ", " << pl.g << endl;

    if (finout.eof()){       // eof() 方法用于判断是否读到文件的末尾, 如果返回true, 此时 finout对象 内部会设置一个 eofbit 标志位, 这时候 finout 在没有使用 clear() 重置状态之前将 无法再次读写该文件!!
        finout.clear();      // 由于后面还要再操作文件, 所以先重置一下 eofbit  
    }

    cout << "Enter planet name: ";
    cin.get(pl.name ,20);
    while(cin.get() != '\n');
    cout << "Enter planet population: ";
    cin >> pl.population;
    cout << "Enter planet's accelaration gravity: ";
    cin >> pl.g;

    // 写文件时, 定位指针用 seekp()
    finout.seekp(place);
    finout.write((char *) &pl, sizeof pl);
    
    // 显式一下修改后的内容
    finout.seekg(0);        // 把指针放回文件开头
    ct = 0;
    cout << "Here are the current contents of the " << file << endl;
    while(finout.read((char *) &pl, sizeof pl)){      // 二进制文件的读取方式: .read((char *) &对象, sizeof 对象)
        cout << ct++ << ": " <<  pl.name << ": " << setprecision(1) << pl.population << ", " << pl.g << endl; // ct++ 表示执行完这行代码之后自增1 
    }

    finout.close();
    return 0;
}