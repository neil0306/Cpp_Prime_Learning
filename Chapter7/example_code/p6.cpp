#include <iostream>

using namespace std;

const int MAX = 40;

int fillArray(double arr[], int size);

void showArray(double arr[], int n);

void reverseArray(double arr[], int n);

int main(void)
{
    double array[MAX];

    int size = fillArray(array, MAX);           // 填数据
    showArray(array, size);                     // 显示当前数据

    // 第一次反转
    reverseArray(array, size);
    showArray(array, size);

    // 第二次反转
    reverseArray(array+1, size-2);      // 反转从第二个元素开始, 到倒数第二个元素结束
    // reverseArray(&array[1], size-2); // 与上一行等价
    showArray(array, size);             // 显示结果

    return 0;
}

int fillArray(double arr[], int size)
{
    int i = 0;  // 统计实际输入了几个

    for (; i < size; i++){
        int tmp;
        cout << "Please enter the #" << i+1 << " number (q to terminate): ";
        cin  >> tmp;
        
        if (!cin){  // 触发非法输入时, 清空缓冲区
            cin.clear();
            // 也可以省略掉continue, 写成: while(cin.get() != '\n');
            while(cin.get() != '\n'){
                continue;
            }
            break;
        }
        else{
            arr[i] = tmp;
        }
    }

    return i;
}

void showArray(double arr[], int size)
{
    cout << "Array content: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void reverseArray(double arr[], int size)
{
    double tmp;
    for (int i = 0; i < size/2; i++){  // 注意除二取整的操作
        tmp = arr[i];
        arr[i] = arr[size - i - 1];     // 别忘了减去 i 和 1
        arr[size - i - 1] = tmp;
    } 
}