#include <iostream>
#include <string>
#include <new>      // 要使用定位new运算一定要引入这个头文件

using namespace std;

const int BUF = 512;

class JustTesting
{
    private:
        string words;
        int number;
    public:
        JustTesting(const string &s = "Just Testing", int n = 0)      // 默认构造
        {
            words = s;
            number = n;
            cout << words << " constructed." << endl;
        }
        ~JustTesting()
        {
            cout << words << " Destroyed\n";
        }

        void show() const
        {
            cout << words << ", " << number << endl;
        }
};


int main(void)
{
    char * buffer = new char[BUF];
    JustTesting *pc1, *pc2;

    pc1 = new(buffer) JustTesting;      // 使用定位new的方式创建对象, 此时使用的是默认构造
                                        // 注意定位new不能delete
    pc2 = new JustTesting("Heap1", 20);           // 触发默认构造

    // 打印在内存中的地址
    cout << "buffer: " << (void *) buffer << endl;    // 如果不进行强制类型转换的话, 这里会直接输出buffer里的内容
    cout << "heap: " << pc2 << endl;

    cout << pc1 << ": ";
    pc1->show();
    cout << pc2 << ": ";
    pc2->show();

    JustTesting *pc3, *pc4;
    pc3 = new(buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6);  // 在没有清空buffer的前提下继续往里塞东西
    pc4 = new JustTesting("Heap2", 10);
    // 打印在内存中的地址
    cout << pc3 << ": ";
    pc3->show();
    cout << pc4 << ": ";
    pc4->show();

    // 注意: 前面所有的对象都没有自动触发析构, 需要使用delete才行, 但是 定位new 不应该用 delete!!!
    // delete pc2;
    // delete pc4;
    // // delete pc1;     // 这里的pc1虽然是定位new, 但是从打印地址的输出信息可以看到, 这行代码本质上等价于 delete [] buffer, 但此时会触发析构哦!
    // // delete pc3;     // 如果执行上一句pc1后, 由于pc3使用的是定位new, 内容也放在buffer变量对应的内存空间中, 所以到这里就没有内存可以释放了, 于是报错.

    // delete [] buffer;       // 使用定位new对应的变量应该释放最原始的内存空间对应的变量, 也就是这里的buffer, 而不是释放 pc1 和 pc3
    //                         // 此时不会触发 pc1 和 pc3 的析构函数!

    // --- 修改后的析构(按照后进先出的顺序去析构, 因为后面创建的对象可能使用了前面对象的资源) -----
    delete pc2;
    delete pc4;
    pc1 -> ~JustTesting();
    pc3 -> ~JustTesting();
    delete [] buffer;

    return 0;
}