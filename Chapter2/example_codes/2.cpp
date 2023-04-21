
# include <iostream>    // 如果 C++ 程序中需要使用输入输出语句, 则一定要包含 #include <iostream> 和 using namespace std; 
                        // # 号 代表 这句话调用了 "预处理器", 预处理会 **在编译之前** 把 iostream 文件的内容添加到当前程序中.

// using namespace std;  //如果要使得所有的函数都采用这个命名空间, 就把语句放在这里, 不然就放在对应的函数中


//  一个简单的C++程序, 包含两个部分: 函数头 和 函数体
int main(void)     //函数头 (不包含花括号的部分)
{                  //函数体 (花括号的部分)

    using namespace std;    // 这条语句是 搭配 iostream 头文件使用的, 用于指定程序中使用的命名空间
    return 0;               // C++语句, 以分号作为一条语句的结尾
                            // return 0; 表示函数的末尾
}