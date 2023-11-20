#include <iostream>
#include <string>
#include <vector>
#include <algorithm>        // 要使用 for_eatch 就需要引入這個頭文件

using namespace std;

struct Review
{
    string title;
    int rating;
};

bool FillReview(Review &r);
void ShowReview(const Review &r);
bool operator<(const Review r1, const Review r2);
bool worserThan(const Review r1, const Review r2);

int main(void)
{
    vector<Review> book;           // 用vector容器装结构体类型的对象, 近似于一个数组
    Review temp;

    while(FillReview(temp)){
        book.push_back(temp);       // 把temp放入容器的末尾, pushback()方法可以自动调整空间大小
    }

    int num = book.size();

    if(num > 0){
        cout << "You entered the following: " << endl;
        // for (int i = 0; i < num; i++){
        //    ShowReview(book[i]);
        // }
        for_each(book.begin(), book.end(), ShowReview);


        cout << "Reprising: "  << endl;
        // 使用迭代器的方式访问元素
        vector<Review>::iterator pr;        // 拿到一个迭代器 pr
        // for (pr = book.begin(); pr != book.end(); pr++){
        //     ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
        // }
        for_each(book.begin(), book.end(), ShowReview);


        vector<Review> oldlist(book);       // 使用复制构造函数
        if(num > 3){
            book.erase(book.begin()+1, book.begin()+3);  // 注意区间是 "左闭右开", 它不会操作 book.begin()+3 对应的元素
            cout << "After erasing: " << endl;
            // 使用迭代器的方式访问元素
            vector<Review>::iterator pr;        // 拿到一个迭代器 pr
            // for (pr = book.begin(); pr != book.end(); pr++){
            //     ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
            // }
            for_each(book.begin(), book.end(), ShowReview);


            book.insert(book.begin(), oldlist.begin(), oldlist.begin()+2);      // insert(插入位置, 插入內容的起始地址, 插入内容的末尾地址), 这个地址范围也是 "左闭右开" 
            cout << "After inserting: " << endl;
            // 使用迭代器的方式访问元素
            // for (pr = book.begin(); pr != book.end(); pr++){
            //     ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
            // }
            for_each(book.begin(), book.end(), ShowReview);

        }

        book.swap(oldlist); 
        cout << "After swapping: " << endl;
        // 使用迭代器的方式访问元素
        // for (pr = book.begin(); pr != book.end(); pr++){
        //     ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
        // }
        for_each(book.begin(), book.end(), ShowReview);

        // ------- 测试 random_shuffle() -----
        cout << "After random shuffle: " << endl;
        random_shuffle(book.begin(), book.end());
        for_each(book.begin(), book.end(), ShowReview);

        // ------- 测试 sort() -----
        // case1: 测试默认情况下的 sort, 从小到大排序
        cout << "After sorting:" << endl;
        sort(book.begin(), book.end());         // 内部会调用 运算符< 来比较, 由于这里实际上是Review对象进行大小比较, 并且Review里面存在字符串, 所以我们需要重载一下这个运算符
        for_each(book.begin(), book.end(), ShowReview);

        cout << "After sorting2:" << endl;
        sort(book.begin(), book.end(), worserThan);         // 内部会调用 运算符< 来比较, 由于这里实际上是Review对象进行大小比较, 并且Review里面存在字符串, 所以我们需要重载一下这个运算符
        for_each(book.begin(), book.end(), ShowReview);
    }
    else{
        cout << "Done." << endl;
    }

    return 0;
}

bool FillReview(Review &r)
{
    cout << "Please enter bool title (enter 'quit' to quit): ";
    getline(cin, r.title);
    if(r.title == "quit"){
        return false;
    }

    cout << "Enter book rating: " << endl;
    cin >> r.rating;
    if(!cin){                       // 输入异常的时候就会直接return
        return false;
    }
    while(cin.get() != '\n');       // 只要进行过 数字 和 字符 的输入, 就要考虑消除缓冲区的回车

    return true;
}
void ShowReview(const Review &r)
{
    cout << r.rating << "\t" << r.title << endl;
}


// 这里返回的 true 表示 r1 小于 r2
bool operator<(const Review r1, const Review r2)
{
    // 这里排序的方式是: 优先按照title(字符串)顺序进行排序
    if(r1.title < r2.title)
        return true;
    else if(r1.title == r2.title && r1.rating < r2.rating )
        return true;
    else
        return false;
}

bool worserThan(const Review r1, const Review r2)
{
    // 这里排序的方式是: 优先按照rating顺序进行排序
    if(r1.rating < r2.rating)
        return true;
    else{
        return false;
    }
}