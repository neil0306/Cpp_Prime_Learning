/*
    使用Vector类来处理 "随机漫步" 问题.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>        // 访问时间
#include <fstream>      // 用来进行文件IO
#include "vector.h"


using namespace std;
using namespace VECTOR;     // 使用命名空间 VECTOR

int main(void)
{
    double target = 0.0;    // 目标距离
    double dStep = 0.0;     // 步长(数值)
    double direction = 0.0; // 存放走的方向(角度)

    srand(time(NULL));      // 设定随机数的种子岁时间改变而改变

    Vector result(0, 0, Vector::RECT);
    Vector step;            // 移动步长(向量)

    unsigned long steps;    // 统计一共走多少步 

    ofstream fout;         // 用来创建, 打开文本文档
    fout.open("randwalk.tx");

    cout << "Enter target distance(q to quit): ";
    while (cin >> target)
    {
        cout << "Enter the step length: ";
        if(!(cin >> dStep)) // 如果输入的 dStep 为0就直接退出
            break;

        fout << "Target Distance: " << target << ", step size: " <<  dStep;

        while( result.magval() < target){
            fout << steps << ": (x, y) = " << result << endl;    // 这里 result 的输出使用了运算符重载, 重载函数中我们返回的是 ostream, 它其实已经包含了 fstream 的输出流, 故这里可以直接使用
            // 生成一个0~359度之间的随机数
            direction = rand() % 360;                    // 随机数的种子用srand设定
            step.reset(dStep, direction, Vector::POL);   // 按极坐标设定本次随机运动的方向
            result = result + step;                      // 走完之后更新状态, 这里使用了重载的加法
            steps++;                                     // 更新走的步数
        }

        cout << "After " << steps << " steps, the object has the following location.\n";
        cout << result;             // 使用重载输出

        fout << "After " << steps << " steps, the object has the following location.\n";
        fout << result;             // 使用重载输出, 记录到文件中.

        // 显示极坐标系下的状态
        result.polar_mode();        // 修改坐标状态
        cout << result;
        fout << result;             // 写入了文件中

        fout << "Average outward distance per step = " << result.magval() / steps << endl;
        cout << endl;

        // 为下一轮随机漫步初始化
        steps = 0;
        result.reset(0.0, 0.0, Vector::RECT);

        cout << "Enter target distance(q to quit): ";
    }

    cout << "Bye!" << endl;
    return 0;
}
