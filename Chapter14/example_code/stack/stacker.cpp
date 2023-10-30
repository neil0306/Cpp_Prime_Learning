#include <iostream>
#include <cctype>       // 为了使用 toupper()
#include <string>

#include "stack.h"

using namespace std;

int main(void)
{
    char ch;
    string po;       // 定义用来放入栈里的数据, 如果这个数据类型改变了, 则stack.h 里的 ITEM 对应的类型也要改变
    Stack<string> st;       // 将模板类Stack进行了实例化, 然后用这个具体的Stack类实例化一个 "栈" 对象

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
                cout << "Enter a string you want to push to stack...\n";
                cin >> po;
                if(st.isFull()){
                    cout << "stack already full!!" << endl;
                }
                else{
                    st.push(po);
                    cout << "Push " << po << " to stack!" << endl;

                }
                break;
            case 'P':
            case 'p':
                if(st.isEmpty()){
                    cout << "Stack is Empty!" << endl;
                }
                else{
                    st.pop(po);
                    cout << po << " is poped!" << endl;
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