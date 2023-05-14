#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
    char ch;

    cout << "Please enter some characters (enter '@' to terminate): \n";
    
    while( cin.get(ch) && ch != '@')
    {
        if (!(isdigit(ch)))  // 排除数字
        {
            if (ch >= 'A' && ch <= 'Z')
                cout << (char) tolower(ch) << endl;
            else if(ch >= 'a' && ch <= 'z')
                cout << (char) toupper(ch) << endl;
        }
        cin.get(ch);
    }

    cout << "Done! \n";
    return 0;
}