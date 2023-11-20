#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void outint(int n)
{
    cout << n << " ";
}

int main(void)
{
    list<int> one(5, 2);        // 列表中一共5个元素, 每个元素初始化为2

    cout << "list one\t: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl;

    int stuff[5] = {1, 2, 4, 8, 6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff+5);   // two.insert(插入的起始位置, 待写入数据的起始位置, 待写入数据的结束位置)   
    cout << "list two\t: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl;

    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);       // 拷贝构造
    three.insert(three.end(), more, more+6);    // 把more的内容插到 three.end() 之前
    cout << "list three\t: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    // 在three中删掉所的4
    cout << "List three minus 4s: ";
    three.remove(4);                // 删除元素4
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    // 拼接 --> splice
    cout << "List three after splice: ";
    three.splice(three.begin(), one);       // 把 one 的内容添加到 three 的开头, 此时 one 的元素都还在
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    // 删除 "连续的相同元素" 中 除第一个元素之外 的所有元素.
    cout << "List three after unique: ";
    three.unique();     // 效果举例: 33132 --> 3132  (针对连续元素去重)
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    // 升序排序 + 连续元素去重
    cout << "List three after sort & unique: ";
    three.sort();
    three.unique();
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    // 合并 --> merge
    cout << "Sorted two merged into three: ";
    two.sort();      
    three.merge(two); // merge之后, two就被清空
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    cout << "After merge, two's size: " << two.size() << endl;      // 输出 0
    return 0;
}


