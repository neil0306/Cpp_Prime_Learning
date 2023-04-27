#include <iostream>

int main(void)
{
    using namespace std;

    int yams[3];   // 声明一个数组

    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    int yamscost[3] = {20, 30, 5}; // 大花括号进行批量赋值, 之后就不可能再进行批量赋值了.

    cout << "The total yams = " << yams[0] + yams[1] + yams[2] << endl;

    cout << "The package with " << yams[1] << " yams costs " << yamscost[1] << " cents per yam.\n";

    cout << "The total yams cost: " << yams[0]*yamscost[0] + yams[1]*yamscost[1] + yams[2]*yamscost[2] << " cents." << endl;

    // 查看数组大小
    cout << "Size of yams array = " << sizeof(yams) << " bytes."<< endl;
    cout << "Size of one element = " << sizeof(yams[0]) << " bytes."<< endl;
    
    // 测试数组不赋值的打印
    int test[2];
    cout << "Output the uninital array (will output an undifine value), the first elememt is: " << test[0] << endl;
    cout << "Output the uninital array (will output an undifine value), the second elememt is: " << test[1] << endl;

    // 测试数组赋值给另一个数组
    int test_2[2] = {1, 2};
    int test_3[2];
    // test_3 = test_2;    // 编译就报错了, 不能直接赋值给另一个数组
    // cout << "测试数组给数组赋值, 赋值成功的话, test_3 的值为:" << test_3 << endl;

    // 数组部分赋值
    int test_4[5] = {1, 2};   // 只赋值前两个, 后面没赋值的都默认初始化为0
    int test_5[5] = {};       // 花括号内为空, 所有元素都初始化为0
    int i;
    for (i=0; i < 5; i++) {
        cout << "Elements of test_4 are:" << test_4[i] << "\n";
    }
    cout << "------------\n";

    for (i=0; i < 5; i++) {
        cout << "Elements of test_5 are:" << test_5[i] << "\n";
    }
    cout << "------------\n";

    // 当花括号内初始化的元素就是数组全部元素时, 变量声明中可以不写数组长度
    int test_6[] = {1, 2, 3, 4, 5, 6};
    int test_7[] = {};                      // 测试不指定数组大小, 同时花括号内为空, 此时数组长度为0
    // int test_7[6] {1, 2, 3, 4, 5, 6};    // 省略等号也可以, 但是只在 C++ 11 中支持, (mac上安装的版本不支持这个特性, 所以没测试)
    cout << "The size of test_6 is: " << sizeof(test_6)/sizeof(int) << endl;
    cout << "The size of test_7 is: " << sizeof(test_7)/sizeof(int) << endl;  // 空数组长度为0

    return 0;
}