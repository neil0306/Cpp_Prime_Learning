#include <iostream>
#include <cstring>  // left函数中还以选择使用这个库函数里的 strlen() 来计算char数组的长度; 但由于发生函数调用, 存在时间成本

using namespace std;

char * left(const char *str, int n = 1);
unsigned long left(unsigned long num, unsigned int ct);

const int ArSIZE = 80;

int main(void){
    const char * trip = "Hawaii!!";
    unsigned long n = 12345678;
    char * temp;
    int i;
    for (i = 0; i < 10; i++){
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete [] temp;
    }
    return 0;
}

char * left(const char *str, int n)
{
    // 自己遍历一次数组, 直接确定数组里的元素个数
    int m = 0;
    while ( m < n && str[m] != '\0'){
        m++;
    }
    char * p = new char[m+1];
    int i = 0;
    for (; i < m; i++){
        p[i] = str[i];
    }
    p[i] = '\0';  // 最后一个元素填入空字符.
    return p;
} 

// 重载 left, 功能是取出数组的前n位
unsigned long left(unsigned long num, unsigned int ct)
{
    unsigned int digits = 1;              // num 的位数
    unsigned long tmp = num;

    if(ct == 0 || num == 0){
        return 0;
    }

    while(tmp /= 10){       // 除值为0时, 相当于false, 跳出循环
        digits++;
    }

    if (digits > ct){
        ct = digits - ct;            // 计算要除多少次10 
        while (ct --){
            num /= 10;
        }
        return num;
    }
    else {
        return num;
    }
}
