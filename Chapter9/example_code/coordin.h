/*
    这个文件存放了类, 结构, 函数原型的声明等.
*/

// ifndef 用来限制结构体, 类等 被多次定义 (包在 define 和 endif 中间的部分都会被视为 宏 的一部分, 防止出现多次定义.)
#ifndef __COORDIN_H__
#define __COORDIN_H__

#include <iostream>
#include <cmath>

using namespace std;

struct polar   // 极坐标
{
    double distance;
    double angle;
};

struct rect     // 笛卡尔坐标
{
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif  // __COORDIN_H__