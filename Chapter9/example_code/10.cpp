#include <iostream>
#include <new>

using namespace std;

const int BUF = 512;
const int N = 5;

char buffer[BUF];       // 大小为512个字符的空间

int main(void)
{
    double *pd1, *pd2;
    int i;

    cout << "Calling new and placement new " << endl;

    // 常规 new
    pd1 = new double[N];        // N个 double 类型的空间(数组, 是连续的内存地址)
    
    // placement new (定位new)
    pd2 = new (buffer) double[N];  // 以 buffer的地址作为开头, 然后创建连续的 N 个 double 类型的空间
    for (i = 0; i < N; i++){
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    }

    cout << "pd1 address = " << (void *)pd1 << endl;
    cout << "buffer address = " << (void *)buffer << endl;

    // 打印每一个元素的地址, 此时可以看到, pd2 的第一个元素的地址就是buffer的地址
    for(i = 0; i < N; i++){
        cout << pd1[i] << " at " << &pd1[i] << " | ";       // 常规new
        cout << pd2[i] << " at " << &pd2[i] << endl;        // placement new
    }

    cout << " --------- \n";

    cout << "Calling new and placement new a second time. " << endl;
    double *pd3, *pd4;
    // 常规new
    pd3 = new double[N];
    // placement new
    pd4 = new(buffer) double[N];        // 注意, 这里又用了一次 buffer 的首地址(原来的值会被覆盖)

    for(i = 0; i < N; i++){
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    }
    // 打印每一个元素的地址, 此时可以看到, pd4 的第一个元素的地址就是buffer的地址
    for(i = 0; i < N; i++){
        cout << pd3[i] << " at " << &pd4[i] << " | ";       // 常规new
        cout << pd3[i] << " at " << &pd4[i] << endl;        // placement new
    }

    cout << " --------- \n";
    cout << "Calling new and placement new a third time. " << endl;
    delete[] pd1;       // 数组, delete的时候别忘了 []
    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];

    for (i = 0; i < N; i++){
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    }
    // 打印每一个元素的地址, 此时可以看到, pd2 的第一个元素的地址就是buffer的地址
    for(i = 0; i < N; i++){
        cout << pd1[i] << " at " << &pd1[i] << " | ";       // 常规new
        cout << pd2[i] << " at " << &pd2[i] << endl;        // placement new
    }

    // 释放
    delete[] pd1;
    delete[] pd3;

    return 0;
}