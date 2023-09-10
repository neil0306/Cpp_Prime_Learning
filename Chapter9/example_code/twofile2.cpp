#include <iostream>
using namespace std;

extern int tom;         // 全局变量, 使用其他文件定义的全局变量(外部变量)
static int dick = 10;   // 全局变量, 但是只在本文件中可见, 不会与其他文件的同名变量冲突
int harry = 200;        // 全局变量, 在本文件中可见, 也可以在其他文件中可见(其他文件使用这里定义的harry要用 extern 修饰) 

void remote_access (void)
{
    cout << "remote_acceess() report the following address: " << endl;
    cout << "&tom = " << &tom << endl;
    cout << "&dick = " << &dick << endl;
    cout << "&harry = " << &harry << endl;

    cout << "---------------" << endl;
}