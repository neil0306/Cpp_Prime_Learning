#include <iostream>

using namespace std;

struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>
void Swap(T &a, T &b);

template <> void Swap<job>(job &j1, job& j2);  // 显示具体化

void show(job &j);

int main(void)
{
    int i = 10;
    int j = 20;
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    Swap(i,j);              // swap 接收 int 类型
    cout << "After Swap, now i,j = " << i << ", "<< j << endl;

    double x = 24.5;
    double y = 81.7;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    Swap(x,y);              // swap 接收 double 类型
    cout << "After Swap, now x,y = " << x << ", "<< y << endl;

    job Rick = {"Rick", 1000, 10};
    job Jack = {"Jack", 1100, 11};
    show(Rick);
    show(Jack);
    Swap(Rick, Jack);       // 如果直接用第一个Swap定义, 结构体的所有值都会被交换; 
                            // 如果我们不希望把名字交换, 这时候就没办法用 [重载函数模板] 的方式去实现了.
                            // 可以用 "显示具体化" 来处理
    cout << "After Swap:" << endl;
    show(Rick);
    show(Jack);

    return 0;
}

// 定义一个模板函数, 来完成任意类型的参数接收. (在调用时, 编译器自动生成独立的重载函数)
template <typename T>           // 注意 <typename T> 中没有逗号也没有分号
void Swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <> void Swap<job>(job &j1, job& j2)     // 对 job 类型进行"显示具体化", 这里说明的是 "job类型不适用于上面定义的函数模板"
{
    double t1;
    int t2;

    // 交换 工资 的数值
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    // 交换 楼层 的数值
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
} 

void show(job &j)
{
    cout << j.name << ": " << j.salary << " on floor " << j.floor << endl;
}
