#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Report
{
    private:
        string str;
    public:
        Report(string s) : str(s){ cout << "Object created\n";}
        ~Report(){cout << "Object deleted\n";}    // 如果打印了这句话, 则证明智能指针自动调用了析构函数
        void comment(){cout << str << endl;}
};

int main(void)
{
    // 为了防止重定义...这里用花括号限定了变量的作用域...
    {
        // mac使用的g++编译器已经不支持auto_ptr了
        shared_ptr<Report> ps(new Report("Using shared_ptr")); 
        ps->comment();
    }

    {
        unique_ptr<Report> ps(new Report("Using unique_ptr"));
        ps->comment();
    }
    return 0;
}