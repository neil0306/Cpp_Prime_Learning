#include <iostream>
#include <cstring>

using namespace std;

char *getname(void);        // 定义函数的话, 别忘了声明这个函数


int main(void)
{
    char *name;
    name = getname();
    cout << name << " at " << (int *)name << endl;   // 由于 name 是char类型的指针, 所以直接cout会输出对应内存块的字符串, 打印地址需要强制类型转换

    // getname 里使用了 new, 所以不要忘了 delete
    delete [] name;   // 由于 name 指针变量指向的是 char类型数组, 所以也不要忘了 "[]"

    // delete 只会释放申请的内存, 不会删除这个变量, 所以我们可以接着继续用这个变量名, 但是需要重新赋值一个地址
    name = getname();
    cout << name << " at " << (int *)name << endl;   // 由于 name 是char类型的指针, 所以直接cout会输出对应内存块的字符串, 打印地址需要强制类型转换
    delete [] name;

    return 0;
}

char *getname(void)
{
    char tmp[80];                          // 题目说最长输入80个字符, 所以这里的临时数组最长是80 
    char *pn = new char [strlen(tmp) +1];  // 一定要注意 +1, 预留一个位置给 空字符\0

    cout << "Enter your last name: ";
    cin >> tmp;         // 由于last name 这种字符串是不包含空格的, 所以使用cin就可以了

    // 由于数组之间不能直接赋值, 因此需要使用函数 strcpy 或者 strncpy
    strcpy(pn, tmp);    // 参数 strcpy(目标, 源)

    return pn;
}
