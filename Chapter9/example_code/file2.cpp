/*
    这个文件存放的是功能函数.
*/

// < > 表示系统级别的头文件
#include <iostream>
#include <cmath>

// " " 表示自定义的头文件
#include "coordin.h"

using namespace std;

// 功能函数(函数体)
polar rect_to_polar(rect xypos)  // x,y position
{
    polar answer;

    answer.distance = sqrt(xypos.x * xypos.x  + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);    // atan2调库计算角度(弧度制), 本质上是一个反正切函数

    return answer;
}

void show_polar(polar dapos)   // distance angle position
{
    const double Rad_to_deg = 57.29577951;   // 单位转换
    cout << "Distance = " << dapos.distance << endl;
    cout << "Angle = " << dapos.angle * Rad_to_deg << " degrees." << endl;
}
