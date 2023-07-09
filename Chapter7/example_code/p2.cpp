#include <iostream>

using namespace std;
const int MAX = 10;

int fill_golf(double arr[], int n);
void show_golf(double arr[], int n);
double avg_golf(double arr[], int n);


int main(void)
{
    double golf[MAX];

    // 函数1: 记录高尔夫成绩, 返回一共录入了多少个成绩
    int size = fill_golf(golf, MAX);

    if(size > 0){

        // 函数2: 在一行中显示
        show_golf(golf, size);
        // 函数3: 计算平均值
        double result = avg_golf(golf, size);
        cout << "Average score: " << result << endl; 
    }
    else{
        cout << "There is No valid scores entered." << endl;
    }

    return 0;
}

int fill_golf(double arr[], int n)
{
    int i = 0;
    for (; i < MAX; i++){
        cout << "Please enter the score #" << i+1 << ": ";
        
        // 检查输入是否有效
        double temp;
        cin >> temp;
        if (!cin){
            cin.clear();          // 如果输入的不是数字, 需要重置cin
            // 清空缓冲区(以回车作为结束标志)
            while(cin.get() != '\n'){
                continue;
            }
            cout << "Bad input, terminated!" << endl;
            break;
        }
        else if(temp < 0){      // 分数不可能是负数
            cout << "Bad input (negative score!), terminated!" << endl;
            break;
        }
        else{
            arr[i] = temp;
        }
    }

    return i;
}

void show_golf(double arr[], int n)
{
    cout << "You have entered scores: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

double avg_golf(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

    return sum / n;
}