#include <iostream>

int main(void)
{
    using namespace std;

    int n;
    // cout << "Enter numbers in range 1-10 to find my favorite number: " << endl;

    // 不用do, cin 写了两次
    // cin >> n;

    // while (n != 7)
    // {
    //     cout << "Enter numbers in range 1-10 to find my favorite number: " << endl;
    //     cin >> n;
    // }


    // 使用 do-while, cin 只写了一次
    do {
        cout << "Enter numbers in range 1-10 to find my favorite number: " << endl;
        cin >> n;
        cout << "You entered " << n << endl;        // 假如输入的是非数字, 那么 n 的值就是 0
    } while (n != 7);       // 别忘了最后的分号!!

    return 0;
}