#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

void output(string &s)
{
    cout << s << " ";
}

int main(void)
{
    string s1[4] = {"abc", "def", "ghi", "jkl"};
    string s2[2] = {"Hello", "world"};
    string s3[2] = {"good", "morning"};

    vector<string> words(4);
    copy(s1, s1+4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // ---- 测试 back_insert_iterator<类型名> (容器对象) 的使用 ------
    copy(s2, s2+2, back_insert_iterator<vector<string> >(words));   // 对 words 对象创建迭代器, 然后拷贝数据到words中.
    /*
        1. 使用 back_insert_iterator<vector<string> >(words) 创建了一个匿名的 迭代器
        2. 这个迭代器相当于 words 的指针, 所以可以直接填入 copy 中, 作为 目标对象的地址
    */
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // ---- 测试 insert_iterator<类型名> (容器对象, 容器的某个元素位置的地址) 的使用
    copy(s3, s3+2, insert_iterator<vector<string> > (words, words.begin()));   // 对 words 对象创建迭代器(这里指定在起始位置插入内容), 然后拷贝数据到words中.
    /*
        1. 使用 insert_iterator<vector<string> >(words, words.begin()) 创建了一个匿名的 迭代器, 同时指定了插入内容的位置
        2. 这个迭代器相当于 words 的指针, 所以可以直接填入 copy 中, 作为 目标对象的地址
    */
    for_each(words.begin(), words.end(), output);
    cout << endl;

    return 0;
}

