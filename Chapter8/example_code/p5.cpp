#include <iostream>

using namespace std;

template <typename T>
T max5(T t[]);

int main(void)
{
    int arr_i[5] = {1,3,5,7,9};
    double arr_d[5] = {1.3, 22.2, 13.8, 17.9, 14.2};

    cout << "The max value of arr_i: " << max5(arr_i) << endl;
    cout << "The max value of arr_d: " << max5(arr_d) << endl;

    return 0;
}

template <typename T>
T max5(T t[])
{
    T max = t[0];
    for (int i = 1; i < 5; i++){
        if (max < t[i]){
            max = t[i];
        }
    }
    return max;
}
