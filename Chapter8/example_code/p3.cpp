#include <iostream>
#include <string>
#include <cctype>       // 为了使用 toupper 函数

using namespace std;

void to_upper(string &str);

int main(void)
{
    cout << "Enter a string (q to quit): ";
    string str;

    getline(cin, str);
    while( str != "q"){
        to_upper(str);
        cout << str << endl;
        cout << "Enter a string (q to quit): ";
        getline(cin, str);
    }
    cout << "Bye!" << endl;

    return 0;
}

void to_upper(string &str)
{
    for (int i = 0; i < str.size(); i ++){
        str[i] = toupper(str[i]);
    }
}