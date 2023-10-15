#include <iostream>
#include "stringbad.h"

void callme1(StringBad &rsb);       // 按引用传递
void callme2(StringBad rsb);        // 按值传递


int main(void)
{
    StringBad headline1("Hello World!");
    StringBad headline2("Good morning.");
    StringBad sport("I love you Rick");

    cout << "Headline1: " << headline1 << endl; 
    cout << "Headline2: " << headline2 << endl; 
    cout << "Sport: " << sport << endl; 

    callme1(headline1);     // 一切正常
    callme2(headline1);   // 调用按值传递的函数报错了
    return 0;
}

void callme1(StringBad &rsb)    // 按引用传递
{
    cout << "String passed by reference: " << rsb << endl;
}
void callme2(StringBad rsb)     // 按值传递
{
    cout << "String passed by value: " << rsb << endl;
}
