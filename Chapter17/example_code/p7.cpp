#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void ShowStr(const string &str);
void GetStrs(ifstream &fin, vector<string> &v);

class Store
{
    private:
        ofstream &fout;
    public:
        Store(ofstream &out) : fout(out){}
        void operator()(const string &str);
};

void Store::operator()(const string &str)
{
    size_t len = str.size();
    fout.write((char *)&len, sizeof len);   // 先写入字符串长度
    fout.write(str.data(), len);            // 把内容写入文件
}

int main(void)
{
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0'){
        vostr.push_back(temp);
    }

    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);
    
    ofstream fout ("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()){
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file: \n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}

void ShowStr(const string &str)
{
    cout << str << endl;
}

void GetStrs(ifstream &fin, vector<string> &v)
{
    size_t len;
    char * pt;

    // 借助 fin 对象读取文件内容
    while (fin.read((char *)&len, sizeof len)){ // read 函数第一个参数是 "存放读到的内容" 的变量地址, 第二个参数是 读取长度
        pt = new char[len];                     // 从堆中, 开辟一段空间用来临时存放读取的内容, 注意是字符数组
        fin.read(pt, len);
        v.push_back(pt);                        // 字符串常量可以直接用字符数组的名字表示 (他们两是等价的)
        delete [] pt;                           // 字符数组在释放内存时, 需要用 delete []
    }
}