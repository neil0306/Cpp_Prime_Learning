#include <iostream>
#include <string>

using namespace std;
string version1(const string & s1, const string &s2);
const string & version2(string &s1, const string &s2);
const string & version3(string &s1, const string &s2);

int main(void)
{
    string Input;
    string Result;
    string copyStr;

    cout << "Enter a string: ";
    getline(cin, Input);
    copyStr = Input;
    cout << "Your string as entered: " << Input << endl;
    cout << "--------------------" << endl;

    Result = version1(Input, "***");      // 在字符串的前缀和后缀加*
    cout << "Your string enhanced: " << Result << endl;
    cout << "Your original string: " << Input <<  endl;
    cout << "--------------------" << endl;

    Result = version2(Input, "###");        // 注意version2返回的是 "引用" 哦!
    cout << "Your string enhanced: " << Result << endl;
    cout << "Input now becomes: " << Input <<  endl;
    
    cout << "--------------------" << endl;
    Input = copyStr;        // 恢复到初始值
    // 此时 version3 返回的值已经被释放掉了, 在linux中, 程序运行到这里会崩掉
    Result = version3(Input, "@@@");
    cout << "Your string enhanced: " << Result << endl;
    cout << "Input now becomes: " << Input <<  endl;

    return 0;
}

// 1. string类中定义了 char* 到 string类型的转换, 使得我们可以用 char* 直接初始化string对象
// 2. 在函数中, 如果在引用变量前加 const, 那么当引用类型 与 传入的实参类型不匹配时(但可以被正确转换), 
//   编译器会自动创建一个临时变量进行适配
// 3. version1 返回的是"值", 走的是"按值传递"的方式, 变量的值在return时存放到临时内存空间中.
string version1(const string & s1, const string &s2)
{
    return s2 + s1 + s2;
}

// version2 返回的是引用!!!
const string & version2(string &s1, const string &s2)
{
    s1 = s2 + s1 + s2;
    return s1;
}


const string & version3(string &s1, const string &s2)
{
    string tmp;
    tmp = s2 + s1 + s2;
    return tmp;     // 返回引用的时候 tmp 会在函数调用结束时被释放!
}
