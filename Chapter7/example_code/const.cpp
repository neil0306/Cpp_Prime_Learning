/*
const int *pt;  // pt指向的内容不能被修改, 但是pt本身可以修改
int * const pt;  // pt指向的内容可以被修改, 但是pt本身不能修改
const int * const pt;  // pt指向的内容不能被修改, pt本身也不能修改
*/

#include <iostream>

using namespace std;

int main(void){

    int n = 10;
    int m = 100;
    // int *pt = &n;
    const int *pt = &n;     // 使用const之后, 下面的 *pt = 20 会报错
    cout << "1) n = " << n << endl;

    // *pt = 20;
    n = 100;  // 直接修改n的值是可以的, 但是不能通过 const 修饰过的指针进行修改
    cout << "2) n = " << n << endl;

    pt = &m;  // const 修饰过的 pt指针 本身可以修改, 但是不能通过这个指针去修改内存块里的东西
    cout << "*pt = " << *pt << endl;  // 此时 *pt = 100, 虽然有 const 修饰, 但是它已经指向别的内存块了
    cout << "m = " << m << endl;

    return 0;
}

