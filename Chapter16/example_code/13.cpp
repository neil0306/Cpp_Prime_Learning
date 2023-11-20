/*
    演示set的一些基本用法
*/
#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

const int N = 6;

int main(void)
{
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    // set 是一个模板类!
    set<string> A(s1, s1 + N);      // 构造函数里填写的其实是 "迭代器", 本质上就是一个广义指针, 就是地址而已
    set<string> B(s2, s2 + N);

    ostream_iterator<string, char> out(cout, " ");     // 创建输出流迭代器, 迭代器把string转成char类型, 构造函数中传入 cout 表示需要将内容输出到标准输出设备, 输出的每一个元素用空格隔开
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);   // 打印出来可以发现元素去重了, 而且根据字母顺序排序过的
    cout << endl;
    cout << "Set B:";
    copy(B.begin(), B.end(), out);
    cout << endl;

    // 两个集合进行合并 & 排序 & 去重
    cout << "Union of A and B: " << endl;
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    // 求交集 & 排序 & 去重
    cout << "Intersectino of A and B: ";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    // 求A中元素不在B中出现的部分 & 排序 & 去重
    cout << "Difference of A and B: ";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);  // 输出 在A中 但 不在B中 的元素.
    cout << endl;

    // 
    set<string> c;
    cout << "Set C: " << endl;
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(c, c.begin()));  
    /*
        要注意: 
            xx.begin() 返回的是一个常量迭代器, 如果这里直接使用 begin() 方法, 这将导致无法写入数据到C中!
            使用 insert_iterator<> 模板时, 需要注意模板的类型参数填写的是 实例化的容器类型, 这里写的是 set<string> 
    */
    copy(c.begin(), c.end(), out);
    cout << endl;

    string s3("grunngy");
    c.insert(s3);
    cout << "Set c after insertion: " << endl;
    copy(c.begin(), c.end(), out);
    cout << endl;

    cout<< "Showing a range: " << endl;
    copy(c.lower_bound("ghost"), c.upper_bound("spook"), out);
    /*
        lower_bound: 将 键(key) 作为参数, 返回一个迭代器, 这个迭代器指向 "第一个不小于该键参数的成员" 
        upper_bound: 同样将 key 作为参数, 返回的也是一个迭代器, 它指向 "第一个大于该键参数的成员"
    */
    cout << endl;

    return 0;
}
