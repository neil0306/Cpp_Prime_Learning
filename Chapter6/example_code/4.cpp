#include <iostream>

using namespace std;

int main(void)
{
    cout << "This program may reformat your hard disk, and distory all your data.\n";
    cout << "Do you wish to continue? <y/n>" << endl;

    char ch;
    cin.get(ch);

    if ( 'y' == ch || 'Y' == ch )
        cout << "You were warned!" << endl;
    else if ( 'n' == ch || 'N' == ch )
        cout << "A wise choise ..." << endl;
    else
        cout << "That is wasn't a y or n, so I guess I'll trash your disk anyway.\n";

    return 0;
}