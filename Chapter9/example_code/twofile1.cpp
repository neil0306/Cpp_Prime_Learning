#include <iostream>

using namespace std;

void remote_access(void);   // 此函数定义在 twofile2.cpp, 虽然没有使用include, 但是编译的时候是两个文件一起编译, 所以能找到函数定义

int tom = 3;            // 全局变量, 在本文件和其他文件中都可见(其他文件使用此变量需要用extern修饰)
int dick = 30;          // 全局变量, 在本文件和其他文件中都可见(其他文件使用此变量需要用extern修饰)
static int harry = 300;  // 全局变量, 但只在本文件中可见

int main(void)
{
    cout << "main() reports the following address: " << endl;
    cout << "&tom = " << &tom << endl;
    cout << "&dick = " << &dick << endl;
    cout << "&harry = " << &harry << endl;

    cout << "------------\n";

    remote_access();

    return 0;
}