#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>        // 要使用 for_eatch 就需要引入這個頭文件

using namespace std;

struct Review
{
    string title;
    int rating;
    int price;
};

bool FillReview(Review &r);
void ShowReview(const shared_ptr<Review> &pt);
bool operator<(const Review r1, const Review r2);
bool worserThan(const shared_ptr<Review> &pt1, const shared_ptr<Review> &pt2);
bool cheaperThan(const shared_ptr<Review> &pt1, const shared_ptr<Review> &pt2);

int main(void)
{
    vector<shared_ptr<Review> > book;       //改成用智能指针
    Review temp;

    while(FillReview(temp)){
        shared_ptr<Review> pd(new Review(temp));    // 切记: 智能指针一定要用 new 出来的空间进行初始化
        book.push_back(pd);                         // 放入智能指针
    }

    int num = book.size();

    if(num > 0){
        cout << "Choose the way you want to sort the book: " << endl;
        cout << "1: original order \t 2: alphabet order " << endl;
        cout << "3: rating up order \t 4: rating down order " << endl;
        cout << "5: price up order \t 5: price down order " << endl;
        cout << "7: quit " << endl;
        
        int choice;
        while(cin >> choice){
            switch (choice)
            {
            case 1:
                for_each(book.begin(), book.end(), ShowReview);
                break;
            case 2:
                sort(book.begin(), book.end());
                for_each(book.begin(), book.end(), ShowReview);
                break;
            case 3:
                sort(book.begin(), book.end(), worserThan);
                for_each(book.begin(), book.end(), ShowReview);
                break;
            case 4:
                sort(book.begin(), book.end(), worserThan);
                reverse(book.begin(), book.end());
                for_each(book.begin(), book.end(), ShowReview);
                break;
            case 5:
                sort(book.begin(), book.end(), cheaperThan);
                for_each(book.begin(), book.end(), ShowReview);
                break;
            case 6:
                sort(book.begin(), book.end(), cheaperThan);
                reverse(book.begin(), book.end());
                for_each(book.begin(), book.end(), ShowReview);
                break;
            case 7:
                cout << "Done. (enter q to quit)" << endl;
                break;
            }
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

    cout << "Enter book price: " << endl;
    cin >> r.price;

    if(!cin){                       // 输入异常的时候就会直接return
        return false;
    }
    while(cin.get() != '\n');       // 只要进行过 数字 和 字符 的输入, 就要考虑消除缓冲区的回车

    return true;
}
void ShowReview(const shared_ptr<Review> &pt)
{
    cout << pt->rating << "\t" << pt->title << "\t" << pt->price << endl;
}


// 这里返回的 true 表示 r1 小于 r2
bool operator<(const shared_ptr<Review> pt1, const shared_ptr<Review> pt2)
{
    // 这里排序的方式是: 优先按照title(字符串)顺序进行排序
    if(pt1->title < pt2->title)
        return true;
    else if(pt1->title == pt2->title && pt1->rating < pt2->rating )
        return true;
    else
        return false;
}

bool worserThan(const shared_ptr<Review> &pt1, const shared_ptr<Review> &pt2)
{
    // 这里排序的方式是: 优先按照rating顺序进行排序
    if(pt1->rating < pt2->rating)
        return true;
    else{
        return false;
    }
}
bool cheaperThan(const shared_ptr<Review> &pt1, const shared_ptr<Review> &pt2)
{
    // 这里排序的方式是: 优先按照price顺序进行排序
    if(pt1->price < pt2->price)
        return true;
    else{
        return false;
    }
}
