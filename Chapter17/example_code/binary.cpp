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
    ifstream fin;

    cout << fixed;          // 这行语句用来设置 "不使用科学计数法表示数字"

    // ------- 首次尝试显示二进制文件中的内容(此时二进制文件还没创建) -------
    fin.open(file, ios_base::in | ios_base::binary);   // 这里指定的是只读的方式打开(ios_base::in), 如果没有这个文件, 由于是 istream, 这里不会创建这个文件!
    if(fin.is_open()){
        cout << "Here are the current contents of the " << file << endl;
        while(fin.read((char *) &pl, sizeof pl)){      // 二进制文件的读取方式: .read((char *) &对象, sizeof 对象)
            cout << pl.name << ": " << setprecision(0) << pl.population << ", " << pl.g << endl;        // setprecision(0) 表示显示小数, 进行 <四舍五入> 之后显式整数部分
        }
        fin.close();
    }

    ofstream fout;
    fout.open(file, ios_base::out | ios_base::app | ios_base::binary);
    if (!fout.is_open()){
        cout << "cannot open " << file << endl;
        exit(0);
    }

    cout << "Enter planet name (enter blank line to quit)" << endl;
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0'){     // 假如输入了空行, 则此时第一个字符必定是结束符 '\0'
        while(cin.get() != '\n');   // 干掉超过20个字符的输入, 并清掉回车
        cout << "Enter planet population: ";
        cin >> pl.population;
        cout << "Enter the planet's accelaration of gravity: ";
        cin >> pl.g;

        // 切记: 当输入完数字之后, 回车仍在输入缓冲区!
        while (cin.get() != '\n');

        fout.write((char *) &pl, sizeof pl);        // 二进制文件的写入方式: .write((char *) &对象, sizeof 对象)

        // ---- 下一次输入 ----
        cout << "Enter planet name (enter blank line to quit)" << endl;
        cin.get(pl.name, 20);
    } 
    fout.close();

    // ------ 再次尝试显式二进制文件中存储内容  -----
    fin.clear();        // 第二次使用这个对象了, 记得 clear !!!
    fin.open(file, ios_base::in | ios_base::binary);   // 这里指定的是只读的方式打开(ios_base::in), 如果没有这个文件, 由于是 istream, 这里不会创建这个文件!
    if(fin.is_open()){
        cout << "Here are the current contents of the " << file << endl;
        while(fin.read((char *) &pl, sizeof pl)){      // 二进制文件的读取方式: .read((char *) &对象, sizeof 对象)
            cout << pl.name << ": " << setprecision(0) << pl.population << ", " << pl.g << endl;
        }
        fin.close();
    }

    return 0;
}