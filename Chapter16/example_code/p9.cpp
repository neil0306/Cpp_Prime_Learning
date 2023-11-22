#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <ctime>

using namespace std;

const int limit = 1000000;

int main(void)
{
    srand(time(0));

    // a 问
    vector<int> vi0;
    for (int i = 0; i < limit; i++){
        vi0.push_back( (rand() % 1000)) ;       // 想要随机数小于哪个数, 就取模即可
    }

    // b 问
    vector<int> vi(vi0);        // 复制构造函数
    list<int> li(vi0.begin(), vi0.end());

    // c 问
    clock_t start = clock();
    sort(vi.begin(), vi.end());         // 对 Vector 进行排序
    clock_t end = clock();
    cout << "vector: " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    li.sort();
    end = clock();
    cout << "list: " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    // d 问
    copy(vi0.begin(), vi0.end(), li.begin());       // 重置 li 的值
    start = clock();
    copy(li.begin(), li.end(), vi.begin());         // 拷到vector
    sort(vi.begin(), vi.end());                     // 对 vector 排序
    copy(vi.begin(), vi.end(), li.begin());         // 拷回list
    end = clock();
    cout << "new method: " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
