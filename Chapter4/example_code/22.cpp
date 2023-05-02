#include <iostream>
#include <cstring>  // 下面用到了strlen()函数, strcpy(), 所以要包含这个头文件

int main(void)
{
    using namespace std;
    char animal[20] = "bear";
    const char * bird = "wren";   // 加了 const 修饰之后, 不能通过指针修改"指针指向的内存块里面的值" 
                                  // bird 这个指针可以指向任何地址, 但是不能利用 bird 去修改对应内存块里的值

    char * ps;
    cout << animal << " and " << bird << endl;

    // 一种错误的打印指针的方式: 没有初始化, 直接cout打印
    // cout << ps << endl;         // char类型的指针没有进行初始化, 直接用cout打印
    //                             // 打印结果是不确定的, 有些机器可能什么都不打印, 有些机器可以直接会触发错误, 然后把这个进程杀死了

    cout << "Enter a kind of animal: ";
    // cin >> animal;                // 正常捕获输入
    // cout << animal << endl;

    // 下面是错误使用指针, 没有给指针预先指定一个可用的内存块, 然后直接赋值过去, 会发生 segmentation fault
    // cin >> ps;                      // 编译不会报错, 运行会报错.
    // cout << ps << endl;             

    // 下面也是错误的指针用法:
    // 错误1: "wren" 是一个字符串常量, 常量不允许被修改. 
    // 错误2: const 修饰了指针, 不能修改指针指向的内存块里面的值, 哪怕 bird 指向的是一个变量, 这个变量也不允许通过 bird 去修改
    // cin >> bird;                    // 编译就会报错
    
    // 正确用法: 先给 指针 指定一个可操作的地址
    ps = animal;                    // 指针指向了一个可操作的地址
    cin >> ps;
    cout << ps << endl;             // 正常打印, 由于 animal 是一个字符数组, 这个名字可以当做一个指针使用, 所以这里打印的是 animal 的值
    cout << animal << " at " << animal << endl; // 由于 animal 的第一个元素的地址是一个 char 类型地址, 所以输出 animal 的时候会自动输出 animal 的值
    cout << animal << " at " << (int *) animal << endl; // 使用强制类型转换, 把 animal 第一个元素的地址换成 int * 类型, 此时可以打印出 animal 的地址
    cout << ps << " at " << (int *) ps << endl; // 由于 ps 指针 直接指向 animal 的第一个元素, 所以 ps 和 animal 的地址是一样的
    
    // 把 ps 指针改掉
    ps = new char[strlen(animal) + 1]; // 重新分配了一块内存, 用来存放输入的字符串, +1 是为了存放 '\0' 字符
    strcpy(ps, animal);                // 把 animal 的值拷贝到 ps 指向的内存块里面
                                       // 注意, 数组只有在初始化的时候才可以用 = 号把数组的值赋值到另一个数组, 所以这里需要用 strcpy() 函数
                                       //  这里也是有风险的, 因为 如果 ps 指向的内存块可能不够大, 会导致内存块后面的其他位置的值被覆盖掉! 更安全的方式是 nstrcpy(), 注意多一个n
    
    strncpy(ps, animal, 19);           // 更安全的方式, 限制了拷贝的长度, 防止内存块后面的其他位置的值被覆盖掉! 可能会导致不可预计的后果!
    
                    // 提醒: 如果使用string 类的话, 就不用担心数组越界问题了

    cout << "After using strcpy(): " << endl;
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;     // 可以看到 ps 的地址和 animal 的地址不一样了
    delete [] ps;       // 记得释放内存

    return 0;
}