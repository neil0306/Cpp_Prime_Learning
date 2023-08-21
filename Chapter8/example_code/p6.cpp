#include <iostream>
#include <string>

using namespace std;

template <typename T>
T maxn(T t[], int n);

template <> 
string maxn <string> (string str[], int n);

int main(void)
{
    int arr_i[6] = {1,3,5,7,9,11};
    double arr_d[4] = {1.3, 22.2, 13.8, 17.9};

    string str[5] = {"hello world", "good morning", "I love you Rick", "What is this?", "Bye"};

    cout << "The max value of arr_i: " << maxn(arr_i, 6) << endl;
    cout << "The max value of arr_d: " << maxn(arr_d, 4) << endl;
    cout << "The max value of str: " << maxn(str, 5) << endl;

    return 0;
}

template <typename T>
T maxn(T t[], int n)
{
    T max = t[0];
    for (int i = 1; i < n; i++){
        if (max < t[i]){
            max = t[i];
        }
    }
    return max;
}

// 针对 char * 做具体化
template <> 
string maxn <string>(string str[], int n)       // 注意 str 是数组, 别漏了 []
{
    int pos = 0;
    for (int i = 0; i < n; i++){
        if (str[pos].size() < str[i].size()){
            pos = i;
        }
    }
    return str[pos];
}
