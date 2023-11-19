#include <memory>
#include <iostream>
#include <string>

using namespace std;

// int main(void)
// {
//     auto_ptr<string> films[5] = 
//     {
//         auto_ptr<string>(new string ("ABC")),
//         auto_ptr<string>(new string ("DEF")),
//         auto_ptr<string>(new string ("GHI")),
//         auto_ptr<string>(new string ("JKL")),
//         auto_ptr<string>(new string ("XYZ")),
//     };

//     auto_ptr<string> pwin;
//     pwin = films[2];            // 此时 films[2] 指针将没有了访问权限, 权限转交给 pwin 了
//     for(int i = 0; i < 5; i++){
//         cout << *films[i] << endl;      // 到这里会触发 segmentation fault (core dump) 错误
//     }

//     cout << "The winner is " << pwin << endl;       // 这行代码是没问题的
//     return 0;
// }

int main(void)
{
    shared_ptr<string> films[5] = 
    {
        shared_ptr<string>(new string ("ABC")),
        shared_ptr<string>(new string ("DEF")),
        shared_ptr<string>(new string ("GHI")),
        shared_ptr<string>(new string ("JKL")),
        shared_ptr<string>(new string ("XYZ")),
    };

    shared_ptr<string> pwin;
    pwin = films[2];            // 此时 films[2] 指针 与 pwin 都指向同一个对象, 引用计数+1
    for(int i = 0; i < 5; i++){
        cout << *films[i] << endl;      // 到这里会触发 segmentation fault (core dump) 错误
    }

    cout << "The winner is " << *pwin << endl;       // 这行代码是没问题的
    return 0;
}