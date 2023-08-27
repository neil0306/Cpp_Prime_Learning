/*
    验证变量的作用域.
    包含: 
    1. 自动变量
    2. 不同函数里的自动变量
    3. 函数形参里的变量
*/
#include <iostream>

using namespace std;

void oil(int x);

int main(void)
{
    // 自动变量
    int texas = 31; 
    int year = 2011; 
    cout << "In main(), texas = " << texas << ", ";
    cout << "&texas = " << &texas << endl;
    cout << "In main(), year = " << year << ", ";
    cout << "&year = " << &year << endl;

    cout << "------------------------------" << endl;
    cout << "Let run function oil()..." << endl;
    // 测试一下函数形参里的变量 & 不同函数里定义的"同名"自动变量
    oil(texas);
    /*
        运行代码时可以观察到结论:
        1. 在不同函数里, 哪怕是同名的变量texas, 他们也不是同一个(因为变量在内存中的地址不相同)
        2. 应函数形参, 哪怕是传入的参数, 它在函数里会自动执行一次拷贝, 留意 oil 函数的x, 我们传入的是 texas, 
            但是它的地址已经不是 main 函数中 texas 的地址了, 可以看到在函数中 x 使用的是一个新的内存地址来存放传入参数 texas 的值 31
        3. 从2的结果看, 它也证明了函数形参中书写的变量, 在传入的过程中, 它的影响范围(作用域)也仅限于 "参数列表" 这个括号范围内, 因为在函数体里面使用的是一个全新的变量.
            对于引用变量和指针变量, 我们可以理解为: 编译器也还是重新定义了新的"引用变量/指针变量", 并且做了对应的赋值操作.
        4. 当发生作用域重叠时, 编译器会自动访问 "作用域最近" 的那个变量
        5. 代码块的自动变量在 "代码块运行结束时" 就会被自动释放, 此时编译器索引的 "作用域最近" 的自动变量将不包含代码块里的内容.
    */

    cout << "------------------------------" << endl;
    cout << "After running oil(), we have:" << endl;
    cout << "In main(), texas = " << texas << ", ";
    cout << "&texas = " << &texas << endl;
    cout << "In main(), year = " << year << ", ";
    cout << "&year = " << &year << endl;

    return 0;
}

void oil(int x)
{
    // 不同函数里的"同名"自动变量
    int texas = 5;

    cout << "In oil(), texas = " << texas << ", ";
    cout << "&texas = " << &texas << endl;

    // 测试形参变量
    cout << "In oil(), x = " << x << ", ";
    cout << "&x = " << &x << endl;

    {
        int texas = 113;    // 在代码块中重新定义了一个texas, 由于是不同的作用域, 它不会出发"重定义"错误.
        cout << "In oil()'s block, texas = " << texas << ", ";    // 这个语句会使用"作用域最近"的变量定义, 也就是在这个 block 中的texas
        cout << "&texas = " << &texas << endl;

        // 尝试访问一下同一个函数, 不同代码块中的变量x
        cout << "In oil()'s block, x = " << x << ", ";  // 由于处于同一个函数中, x的作用域是包含这个block的, 所以x仍然有效
        cout << "&x = " << &x << endl;                  // 打印结果是: 这个x与上面打印的x是同一个(内存地址也相同)
    }

    cout << "Post-block, texas = " << texas << ", ";
    cout << "&texas = " << &texas << endl;              // 可以看到, 这个texas并不是代码块里的texas, 而是函数体里定义的 texas, 
                                                        // 说明代码块中的 texas 作用域不会超出 block, 并且 block 里的 texas 其实已经被释放掉了.
}
