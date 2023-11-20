#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Review
{
    string title;
    int rating;
};

bool FillReview(Review &r);
void ShowReview(const Review &r);

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
        for (int i = 0; i < num; i++){
            ShowReview(book[i]);
        }

        cout << "Reprising: "  << endl;
        // 使用迭代器的方式访问元素
        vector<Review>::iterator pr;        // 拿到一个迭代器 pr
        for (pr = book.begin(); pr != book.end(); pr++){
            ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
        }

        vector<Review> oldlist(book);       // 使用复制构造函数
        if(num > 3){
            book.erase(book.begin()+1, book.begin()+3);  // 注意区间是 "左闭右开", 它不会操作 book.begin()+3 对应的元素
            cout << "After erasing: " << endl;
            // 使用迭代器的方式访问元素
            vector<Review>::iterator pr;        // 拿到一个迭代器 pr
            for (pr = book.begin(); pr != book.end(); pr++){
                ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
            }

            book.insert(book.begin(), oldlist.begin(), oldlist.begin()+2);      // insert(插入位置, 插入內容的起始地址, 插入内容的末尾地址), 这个地址范围也是 "左闭右开" 
            cout << "After inserting: " << endl;
            // 使用迭代器的方式访问元素
            for (pr = book.begin(); pr != book.end(); pr++){
                ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
            }
        }

        book.swap(oldlist); 
        cout << "After swapping: " << endl;
        // 使用迭代器的方式访问元素
        for (pr = book.begin(); pr != book.end(); pr++){
            ShowReview(*pr);                // 对迭代器进行解引用, 拿到对象
        }
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
