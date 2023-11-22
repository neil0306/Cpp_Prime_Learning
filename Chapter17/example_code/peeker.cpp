/*
    本例子将测试 cin.peek() 和 cin.putback() 方法.
    任务: 将用户输入的#号前的内容打印出来.
*/
#include <iostream>

using namespace std;

int main(void)
{
    char ch;
    // 实现 #号 前的内容全部打印出来
    while(cin.get(ch))              // 当遇到 "文件尾" 的时候, cin会停止捕获, 也就是while条件为 false
    {
        // 注: linux 和 UNIX 模仿"文件尾"的方式是使用键盘组合键: ctrl+d
        if(ch != '#'){
            cout << ch;
        }
        else{
            cin.putback(ch);        // 将 '#' 放回输入缓冲区中
            break;
        }
    }
    cout << endl;
    /*
        这个while循环退出有两种可能:
        1. cin 遇到 "文件尾", 也就是用户使用了 ctrl+d 组合键
        2. 用户输入的时候输入了 #号 (此时用户其实还没有停止输入) 
    */

    if(!cin.eof()){     // 并非遇到 "文件尾" 退出读取的情况, 也就是 用户输入 '#' 的情况
        cin.get(ch);    // 此时捕获到 putback 放回来的 #
        cout << ch << " is your next input character." << endl;
    }
    else{
        cout << "End of input reached." << endl;
        exit(0);
    }

    while(cin.peek() != '#'){          // peek 只是查看缓冲区里的 "下一个元素是什么, 但是没有读取出来, 东西还在缓冲区里"
        cin.get(ch);        // peek没有读取, 这里的cin.get()才是真正读走了缓冲区的内容
        cout << ch;
    }  
    cout << endl;

    // 判断退出情况
    if(!cin.eof()){     // 并非遇到 "文件尾" 退出读取的情况, 也就是 用户输入 '#' 的情况
        cin.get(ch);    // 此时捕获到 putback 放回来的 #
        cout << ch << " is your next input character." << endl;
    }
    else{
        cout << "End of input reached." << endl;
        exit(0);
    }
    return 0;
}