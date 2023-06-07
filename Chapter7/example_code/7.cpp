/*
    数组指针用const做保护的例子
*/

#include <iostream>
const int Max = 5;

int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revaluate(double r, double arr[], int n);


using namespace std;

int main(void){

    double properties[Max];

    int size = fill_array(properties, Max);  // 录入
    
    show_array(properties, size);       // 回显

    if(size > 0){
        cout << "Enter revaluation factor: ";
        double factor;
        while(!(cin >> factor)){    // 检查cin是不是停止工作
            cin.clear();            // 清除cin的标志位
            while(cin.get() != '\n'){  // 清掉cin的缓冲区
                continue;
            }
            cout << "Bad input; Please enter a number: ";
        }
        revaluate(factor, properties, size); // 重新评估(重新写入数据)
        show_array(properties, size);       // 回显
    }


    return 0;
}


int fill_array(double arr[], int limit){
    double temp;
    int i = 0;
    for(; i < limit; i++){
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin){  // 检查cin是不是停止工作
            cin.clear();  // 清楚cin的标志位
            while (cin.get() != '\n'){
                continue;
            }
            cout << "Bad input; input process terminated.\n";
            break;
        } else if( temp < 0 ){
            break;
        } else {
            arr[i] = temp;
        }
    }
    return i; // 返回成功录入的个数
}

void show_array(const double arr[], int n ){   // const 保护数组指针指向的内容
    for(int i = 0; i < n; i++){
        cout << "Property #" << (i + 1) << ": $";
        cout << arr[i] << endl;
    }
}
void revaluate(double r, double arr[], int n){

    for(int i = 0; i < n; i++){
        arr[i] *= r;
    }
}
