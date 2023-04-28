#include <iostream>

int main(void)
{
    using namespace std;

    int nights = 1001;
    int *pt = new int;

    *pt = 1001;

    cout << "nights value = " << nights << ": location: " << &nights << endl;
    cout << "int value = " << *pt << ": location: " << pt << endl;

    double *pd = new double;
    *pd = 1000001.0;

    cout << "double value = " << *pd << ": location: " << pd << endl;

    // 查看指针变量的地址
    cout << "location of pointer pd: " << &pd << endl;

    // 查看指针变量占用内存的大小
    cout << "Size of pt = " << sizeof(pt) << endl;    // pt是一个指针变量，所以占用8个字节
    cout << "Size of *pt = " << sizeof(*pt) << endl;  // *pt是一个 int 类型的变量，所以占用4个字节
    cout << "Size of pd = " << sizeof(pd) << endl;    // pd是一个指针变量，所以占用8个字节 (和pt指针相同)
    cout << "Size of *pd = " << sizeof(*pd) << endl;  // *pd是一个 double 类型的变量，所以占用8个字节

    return 0;
}