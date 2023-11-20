#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

typedef int KeyType;
typedef multimap<KeyType, string> MapCode;
typedef pair<KeyType,string> Pair;

int main(void)
{
    MapCode codes;                      // key 为 int, value 为 string
    codes.insert(Pair(10, "Beijing"));      // 由于insert只能接受 一个 参数, 所以这里为了传入 key-value, 就使用了 pair<int,string> 数据类型
    codes.insert(Pair(21, "Shanghai")); 
    codes.insert(Pair(22, "Tianjin")); 
    codes.insert(Pair(23, "Chongqing")); 
    codes.insert(Pair(24, "Shenyang")); 
    codes.insert(Pair(22, "Nanjing")); 

    cout << "Number of cities with area code 22: " << codes.count(22) << endl;

    MapCode::iterator it;
    cout << "Area code \t city" << endl;
    for(it = codes.begin(); it != codes.end(); it++ ){
        cout << (*it).first << " \t\t " << (*it).second << endl;   // first 对应键, second 对应值
    }

    cout << "Cities with area code 22: " << endl;
    pair<MapCode::iterator, MapCode::iterator> range =  codes.equal_range(22);            // pair 可以把两种类型的值放到一个对象中
    /*
        equal_range()方法返回两个迭代器(两个指针), 第一个是 "匹配到指定key的第一个元素的位置", 第二个是 "匹配到指定key的最后一个元素的位置的下一个位置(超尾)"
    */

    for(it = range.first; it != range.second; it++){        // range里的 second 指的是 MapCode::iterator
        cout << (*it).second << endl;       // it 的 second 指的是 MapCode (其实是multimap) 里的 value
    }

    return 0;
}

