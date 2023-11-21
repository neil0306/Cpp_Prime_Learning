#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool same_after_reverse(const string &s);

int main(void)
{
    string str;

    cout << "Please enter a string: ";
    cin >> str;

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
    temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}