#include <iostream>

int main(void)
{
    using namespace std;
    
    int year;
    char address[80];

    cout << "What year was your house built?\n";
    // cin >> year;                // cin 不会读取换行符(回车), 换行符仍然保留在系统缓冲区, 此时会触发一个bug, 下面的address会直接读取这个换行符, 导致用户无法输入address
    // cin.get();                  // 用 get() 干掉一个字符
    // 或者写成 (cin >> year).get()
    (cin >> year).get();

    cout << "What is its street address?\n";
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;

    return 0;
}