#include <iostream>

using namespace std;

template <typename T>
void ShowArray(T arr[], int n);      // #1

template <typename T>
void ShowArray(T * arr[], int n);    // #2

struct debts
{
    char name[50];
    double amount;
};

int main(void)
{
    int things[6] = {13, 31, 03, 301, 310, 130};

    ShowArray(things, 6);

    struct debts mr_E[3] =      // 这个 struct 加不加都可以
    {
        {"Rick", 2400.00},
        {"Jack", 1300.00},
        {"Rose", 1800.00}
    };

    double *pd[3];   // 指针数组, 数组有3个元素, 每个元素都是double类型的指针

    for(int i = 0; i < 3; i++){
        pd[i] = &mr_E[i].amount;        // 传递数据的指针
    }
    
    ShowArray(pd, 3);       // 此时若匹配到 #1, 打印出来的是地址; 如果匹配到 #2, 则正常输出.
                            // 从实验结果来看, 会匹配到#2, 而且 #2 确实是"最省事"的

    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)      // #1 
{
    cout << "Template A: " << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)    // #2
{
    cout << "Template B: " << endl;
    for (int i = 0; i < n; i++){
        cout << *arr[i] << " " ;
    }
    cout << endl;
}
