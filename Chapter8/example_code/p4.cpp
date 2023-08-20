#include <iostream>
#include <cstring>

using namespace std;
struct stringy
{
    char *str;
    int ct;
};

void set(stringy &str, const char *source);
void show(const stringy & beany, int n = 1);
void show(const char *str, int n = 1);

int main(void)
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    cout << "----" << endl;
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    delete beany.str;
    return 0;
}

void set(stringy &str, const char *source)
{
    str.ct = strlen(source) + 1;        // 记录字符串的大小
    str.str = new char[str.ct];         // 注意应该使用方括号!!
    strcpy(str.str, source);
}

void show(const stringy & beany, int n)
{
    for (int i = 0; i < n; i++){
        cout << beany.str << endl;
    }
}

void show(const char *str, int n)
{
    for (int i = 0; i < n; i++){
        cout << str << endl;
    }
}