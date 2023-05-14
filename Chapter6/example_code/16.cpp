#include <iostream>
#include <fstream>   // 文件IO一定要包含的库文件, 里面有操作文件时需要的"对象的定义"



using namespace std;

int main(void)
{
    char automobile[50];
    int year;
    double a_price, d_price;

    // ostream 里已经定义好了 cout; istream 里定义好了 cin, 所以可以直接使用, 不需要自己定义.
    // fstream 中 只有 ofstream 和 ifstream, "还没有给我们弄好对象", 所以进行文件IO的第一步是创建对象.

    ofstream outFile;                   // 1. 用 ofstream 类, 创建一个输出文件流对象 outFile
    outFile.open("carInfo.txt");        // 2. 将对象与文件关联起来 (此时这个文件可以还没有创建, 这个对象会自动创建文件)


    cout << "Enter the make and the model of automobile: ";
    cin.getline(automobile, 50);

    cout << "Enter the model year: ";
    cin >> year;

    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = a_price * 0.913;

    // 将信息输出到 屏幕 上
    cout << fixed;                  // 用小数点表示数字
    cout.precision(2);              // 显示时, 保留小数点后两位的精度
    cout.setf(ios_base::showpoint); // 设置一定要显示小数点和小数部分 
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "asking price: " << a_price << endl;
    cout << "now price: " << d_price << endl;

    // 将信息输出到 文件 中 (覆盖写!!)
    // trick: cout 怎么用, outFile 就怎么用
    outFile << fixed;                  // 用小数点表示数字
    outFile.precision(2);              // 显示时, 保留小数点后两位的精度
    outFile.setf(ios_base::showpoint); // 设置一定要显示小数点和小数部分 
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "asking price: " << a_price << endl;
    outFile << "now price: " << d_price << endl;

    outFile.close();

    /*
    注意:
        如果多次运行这个程序, 不难发现它执行的是 覆盖写, 已有文本中的内容被丢弃了.
        原因:
            outFile.open() 这个 open 方法会直接丢弃文本内原有的内容!!!
    */

    return 0;
}