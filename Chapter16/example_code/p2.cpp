#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>       // tolower, isalpha

using namespace std;

bool same_after_reverse(const string &s);

int main(void)
{
    string str;

    cout << "Please enter a string: ";
    getline(cin, str);

    if(same_after_reverse(str)){
        cout << "Palindromic" << endl;
    }
    else{
        cout << "Not Palindromic." << endl;
    }
    return 0;
}

bool same_after_reverse(const string &s)
{
    string temp;
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            temp += tolower(s[i]);      // 直接追加到 temp 末尾
        }
    }
    string temp1 = temp;
    reverse(temp1.begin(), temp1.end());
    return temp1 == temp;
}