/*
    使用Vector类来处理 "随机漫步" 问题.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>        // 访问时间
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

    unsigned long steps = 0;    // 统计一共走多少步 
    unsigned int N;
    unsigned int max_step = 0;
    unsigned int min_step = 0;
    unsigned int sum_step = 0;

    cout << "How many times do you want to try: ";
    cin >> N;

    cout << "Enter the target distance: ";
    cin >> target;

    cout << "Enter the step lenth: ";
    cin >> dStep;

    for(int i = 0; i < N; i++){
        while(result.magval() < target){
            // 生成一个0~359度之间的随机数
            direction = rand() % 360;                    // 随机数的种子用srand设定
            step.reset(dStep, direction, Vector::POL);   // 按极坐标设定本次随机运动的方向
            result = result + step;                      // 走完之后更新状态, 这里使用了重载的加法
            steps++;                                     // 更新走的步数
        }

        max_step = (max_step > steps) ? max_step : steps;
        if (min_step == 0){  // 防止第一次运行时 min_step 不进行更新
            min_step = max_step;
        }
        min_step = (min_step < steps) ? min_step : steps;
        sum_step += steps;

        // 为下一轮随机漫步初始化
        steps = 0;
        result.reset(0.0, 0.0, Vector::RECT);
    }

    cout << "The Max_step steps is: " << max_step << endl;
    cout << "The Min steps is: " << min_step << endl;
    cout << "The average steps is: " << (double) sum_step / N << endl;

    cout << "Bye!" << endl;
    return 0;
}
