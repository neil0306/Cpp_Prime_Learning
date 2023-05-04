#include <iostream>
using namespace std;

int main(void){

    int a = 20;
    int b = 20;

    cout << "a = " << a << ", b = "<< b << endl;

     // 变量在右侧时, 先做自增; 变量在左侧时, 先做完别的事情, 再自增
    cout << "a++ = " << a++ << ", ++b = "<< ++b << endl;   // 输出 a++ = 20, ++b = 21
    cout << "a = " << a << ", b = "<< b << endl;            // 输出 a = 21, b = 21

    return 0;
}