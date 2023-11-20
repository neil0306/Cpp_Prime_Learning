#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(void)
{
    int casts[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> dice(10);
    
    // 将数组的内容拷贝到容器中
    copy(casts, casts+10, dice.begin());        // copy(源变量开始地址, 源变量结束地址, 目标容器存放数据的起始地址)

    ostream_iterator<int, char> out_iter(cout, " "); // STL提供的输出迭代器的模板: ostream_iterator<原来的类型, 用于输出的类型> 变量名(输出流对象, 内容分隔字符)
    copy(dice.begin(), dice.end(), out_iter);   // 用copy拷贝数据过到输出迭代器 out_iter, 前面已经将out_iter与cout关联起来, 故能完成输出
    cout << endl;
    cout << "----------" << endl;

    // 用倒序输出
    copy(dice.rbegin(), dice.rend(), out_iter);   // rbegin: 倒数的开始; rend: 倒数的结束
    cout << endl;
    cout << "----------" << endl;

    // 注意: rbegin 和 rend 返回的是 reverse_iterator 类型
    vector<int>::reverse_iterator ri;   // 因为 dice 是vector<int>类型, 所以这里从 vector<int> 中获取 反向迭代器 
    for(ri = dice.rbegin(); ri != dice.rend(); ri++){
        cout << *ri << " ";
    }
    cout << endl;


    return 0;
}