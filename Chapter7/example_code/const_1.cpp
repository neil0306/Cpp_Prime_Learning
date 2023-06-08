/*
int * const pt;  // pt指向的内容可以被修改, 但是pt本身不能修改
*/

#include <iostream>

using namespace std;

int main(void){

    int n = 10;
    int m = 100;
    int *const pt = &n;     // 注意: 此时const位于*的右侧

    cout << "1) n = " << n << endl;
    *pt = 20;               // 此时可以修改pt指针的内容
    cout << "2) n = " << n << endl;

    // pt = &m;                // 报错, 因为pt 被 const 修饰, pt 是只读的, pt不能指向其它内存地址了 

    return 0;
}

