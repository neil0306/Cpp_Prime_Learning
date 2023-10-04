#include <iostream>
#include <cctype>       // 为了使用 toupper()
#include "stack.h"

using namespace std;

int main(void)
{
    char ch;
    customer cust;
    double sum = 0.0;

    Stack st;               // 实例化一个 "栈" 对象

    cout << "Please Enter A to push to stack, \n"
        << "P to pop from stack, \n"
        << "Q to quit." << endl;

    // 判断输入是否合法, 并且判断是否对栈进行操作
    while(cin >> ch && toupper(ch) != 'Q'){
        while(cin.get() != '\n'){        // 处理缓冲区里的回车
            continue;
        }
        switch(ch)        
        {
            case 'A':
            case 'a':
                cout << "Enter a customer's fullname you want to push to stack...\n";
                cin.getline(cust.fullname, 35);
                cout << "Enter a customer's payment you want to push to stack...\n";
                cin >> cust.payment;

                if(st.isFull()){
                    cout << "stack already full!!" << endl;
                }
                else{
                    st.push(cust);
                }
                break;
            case 'P':
            case 'p':
                if(st.isEmpty()){
                    cout << "Stack is Empty!" << endl;
                }
                else{
                    st.pop(cust);
                    sum += cust.payment;
                    cout << cust.fullname << " is poped!" << endl;
                    cout << cust.payment << " is poped!" << endl;
                    cout << "Sum Payment = " << sum << endl;
                }
                break;
        }

        // 提示输入下一组数据
        cout << "Please Enter A to push to stack, \n"
        << "P to pop from stack, \n"
        << "Q to quit." << endl;
    }
    return 0;
}