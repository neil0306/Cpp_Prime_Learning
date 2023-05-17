#include <iostream>

using namespace std;

const int strsize = 40;
const int usersize = 4;

void showmenu(void);
void print_by_fullname();
void print_by_title();
void print_by_bopname();
void print_by_pref();


struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

bop user[usersize] = 
    {
        {"Rick", "Level_A", "RR", 0},
        {"Jack", "Level_B", "JJ", 1},
        {"Michael", "Level_C", "MM", 2},
        {"Ning", "Level_S", "GG", 2}
    };

int main(void)
{
    showmenu();
    
    char choice;
    cin.get(choice).get(); // 每次输入都有一个回车, 消耗这个回车

    while (choice != 'q')
    {
        switch (choice)
        {
            case 'a' : print_by_fullname(); break;
            case 'b' : print_by_title(); break;
            case 'c' : print_by_bopname(); break;
            case 'd' : print_by_pref(); break;
            default : cout << "Please enter character a, b, c, d, q: \n"; 
        }
        cout << "Next input: ";
        cin.get(choice).get();
    }

    cout << "bye!" << endl;

    return 0;
}

void showmenu(void)
{
    cout << "Benevolent Order of Programmers Report\n";
    cout << "a. display by name \t b. display by title\n";
    cout << "c. display by bopname \t d. display by preferece\n";
    cout << "q. quit\n";
    cout << "Enter your choice: ";
}


void print_by_fullname(void)
{
    for (int i = 0; i < usersize; i++ )
        cout << user[i].fullname << endl; 
}

void print_by_title(void)
{
    for (int i = 0; i < usersize; i++ )
        cout << user[i].title << endl; 
}

void print_by_bopname(void)
{
    for (int i = 0; i < usersize; i++ )
        cout << user[i].bopname << endl; 
}

void print_by_pref(void)
{
    for (int i = 0; i < usersize; i++ )
    {
        switch (user[i].preference)
        {
            case 0 : cout << user[i].fullname << endl; break;
            case 1 : cout << user[i].title << endl; break;
            case 2 : cout << user[i].bopname << endl; break;
        }
    }
}