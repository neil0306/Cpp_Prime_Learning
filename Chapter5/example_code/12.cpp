#include <iostream>

int main(void){
    using namespace std;

    int arr[10] = {20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

    cout << "Doing it right: " << endl;
    int i;
    for (i = 0; arr[i] == 20; i++)
        cout << "arr[" << i << "] = " << arr[i] << endl;
    
    // 死循环
    // cout << "Doing it dangerously wrong: " << endl;
    // for (i = 0; arr[i] = 20; i++)           // 判断语句写成了赋值语句, 这条赋值表达式的返回值是 =号 的左值, 也就是20, 所以这条语句永远为真, 
    //                                         // 又由于 C/C++ 不去判断数组越界问题, 所以就死循环了
    //                                         // 程序运行到最后会停止, 愿意是使用的这块内存空间刚好跑到了不允许访问的区域, 然后就报错, 停止运行
    //     cout << "arr[" << i << "] = " << arr[i] << endl;
    
    return 0;
}