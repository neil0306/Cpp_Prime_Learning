#ifndef __SUPPORT_H__
#define __SUPPORT_H__

#include <iostream>

// 声明一个外部变量, 这个变量的初始声明位置不是在本文件中, 而是在external.cpp里
// 经过外部声明的变量, 就可以使用其他地方声明的全局变量了(extern关键词表明当前这个变量是从外面来的).
extern double warming;  // 注意, 这里的warming不要进行赋值!

void update(double dt);

void local(void);

#endif