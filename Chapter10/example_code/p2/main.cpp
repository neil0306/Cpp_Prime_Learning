#include "p2.h"
#include <iostream>

int main(void)
{
    Person one;     // 使用默认构造
    Person two("Rick"); // 只提供Last name
    Person three("Michael", "Jackson");

    one.show();
    one.FormalShow();

    cout << "-----" << endl;
    two.show();
    two.FormalShow();

    cout << "-----" << endl;
    three.show();
    three.FormalShow();

    return 0;
}