#include <iostream>
#include <cstring>  // left函数中还以选择使用这个库函数里的 strlen() 来计算char数组的长度; 但由于发生函数调用, 存在时间成本

using namespace std;

char * left(const char *str, int n = 1);
const int ArSIZE = 80;

int main(void){
    char sample[ArSIZE];
    cout << "Enter a string:";
    cin.get(sample, ArSIZE);

    // char *ps = left(sample, 4);
    char *ps = left(sample, 400000);  // 如果使用版本1, 就会浪费很多空间
    cout << ps << endl;

    ps = left(sample); // 使用默认值
    cout << ps << endl;

    delete ps;      // 在 left 里面 new, 这里delete
    
    return 0;
}

// // 版本1: 速度快, 但存在空间浪费
// char * left(const char *str, int n)
// {
//     if (n < 0)
//         n = 0;      // n < 0 是非法的, 此时直接置零, 相当于什么都不干

//     char *p = new char [n+1];               // 要多一个, 存放结束符 '\0'

//     int i = 0;
//     for(i = 0; i < n && str[i]; i++){       // str[i] 如果为空字符, 此时for循环的条件语句就返回false
//         p[i] = str[i];
//     }
//     while (i <= n){
//         // 先对第i个位置赋值, 然后 i++
//         p[i++] = '\0';      // 如果p没有存满(此时str里的元素不足n个), 此时就把空出来的位置全部填 '\0'
//     }
//     return p;
// }

// 版本2: 不但节省空间, 运行速度也快
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
