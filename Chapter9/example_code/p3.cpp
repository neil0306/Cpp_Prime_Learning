#include <iostream>
#include <cstring>      // 使用strcpy函数
#include <new>

using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

void show(const chaff &p);

const int BUF = 512;
char buffer[BUF];       // 为了使用placement new

int main(void)
{
    // method 1: 定位new
    chaff *pd1 = new(buffer) chaff[2];      // 一个结构体类型指针, 指向一个结构体数组, 数组有两个元素

    // method 2: 常规new
    chaff *pd2 = new chaff[2];

    char dross[20] = "";
    int slag = 0;

    // 赋值
    for(int i = 0; i < 2; i++){
        cout << "#" << i+1 << ": " << endl;
        cout << "Enter the dross: ";
        cin.getline(dross, 20);
        cout << "Enter the slag: ";
        cin >> slag;
        cin.get();      // 消耗掉缓冲区的回车

        strcpy(pd1[i].dross, dross);
        strcpy(pd2[i].dross, dross);
        pd1[i].slag = slag;
        pd2[i].slag = slag;
    }

    cout << "\n";
    for(int i = 0; i < 2; i++){
        show(pd1[i]);
        show(pd2[i]);
        cout << "-------" << endl;
    }

    delete[] pd2;       // 注意 pd1 是静态空间, 不能delete
    return 0;
}

void show(const chaff &p)
{
    cout << "The dross is: " << p.dross << endl;
    cout << "The slag is: " << p.slag << endl;
}