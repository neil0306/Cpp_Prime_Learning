#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void)
{
    set<string> Mat, Pat, Guest;

    cout << "Enter Mat's friends name (quit to quit): " << endl;
    string name;
    while(getline(cin, name) && name != "quit"){
        Mat.insert(name);
    }

    cout << "Enter Pat's friends name (quit to quit): " << endl;
    while(getline(cin, name) && name != "quit"){
        Pat.insert(name);
    }

    // 合并: 由于 set 本身就排序 & 去重, 所以直接丢进去就好了
    Guest.insert(Mat.begin(), Mat.end());
    Guest.insert(Pat.begin(), Pat.end());
    set<string>::iterator pd;
    cout << "Guest: ";
    for(pd = Guest.begin(); pd != Guest.end(); pd++){
        cout << *pd << " ";
    }
    cout << endl;

    return 0;
}