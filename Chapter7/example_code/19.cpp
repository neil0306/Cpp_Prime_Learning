/*
7.10.2 函数指针例题
*/
#include <iostream>

using namespace std;
const double * f1(const double* ar, int n);
const double * f2 (const double ar[], int n);
const double * f3 (const double ar[], int n);

int main(void)
{
    double av[3] = {1112.3, 1542.6, 2227.9};

    // part1: 定义一个指向函数的指针
    const double * (*p1)(const double *, int) = f1; // p1 是函数指针, 指向函数f1
    auto p2 = f2;           // 使用auto关键字 (C++ 11的关键字), 自动推断类型, 交给编译器自动完成
    cout << "Part1 output: ------------------" << endl;
    cout << "Address       Value" << endl;
    cout << (*p1)(av, 3) << ": " << *((*p1)(av,3)) << endl;        // (*p1) 才是 f1 本身
    cout << p2(av, 3) << ": " << *p2(av,3) << endl;                // p2(av, 3) 等价于 f2(av, 3)
    
    // part2: 定义函数指针数组
    const double * (*pa[3])(const double *, int) = {f1, f2 , f3};    // pa 是一个数组, 数组元素是指向函数的指针
    auto pb = pa;                                      // 使用auto关键字 (C++ 11的关键字), 自动推断类型, 交给编译器自动完成

    cout << "Part2 output: ------------------" << endl;
    cout << "Address       Value" << endl;
    for (int i = 0; i < 3; i++){
        cout <<  pa[i](av, 3) << ": " <<  *pa[i](av, 3) << endl;               // 调用了3个函数, 返回值是double类型的指针
    }
    for (int i = 0; i < 3; i++){
        cout <<  pb[i](av, 3) <<  ": " << *pb[i](av, 3) << endl;               // 调用了3个函数, 返回值是double类型的指针
    }

    // part3 : 函数指针数组 的指针
    auto pc = &pa;  // &pa取出数组的首地址, pc 是指向数组pa的指针 (pa则是一个函数指针数组)
    
    // 上面 pc 定义语句的写法等价于:
    // 解读: 
    //      (*pc)表示pc是一个指针;
    //      (*pc)[3] 表示pc是一个指针, 指向一个包含3个元素的数组;
    //      *(*pc)[3] 表示pc是一个指针, 指向一个包含3个元素的数组, 数组中的每一个元素也都是指针 【这里的定义细化到数组元素级别】.
    //      const double *(*(*pc)[3])(const double *, int), 把 *(*pc)[3] 看做一个整体, 
    //          此时的语法就是定义函数指针的语法, 它是针对数组里的每一个元素定义的, 这里说明数组元素是一个函数指针 【这里的定义细化到数组元素级别】
    // const double *(*(*pc)[3])(const double *, int) = &pa;

    const double *( *(*pd)[3] ) (const double *, int) = &pa;

    cout << "Part3 output: ------------------" << endl;
    cout << "Address       Value" << endl;
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;     // pc是指向数组pa的指针, *pc是pa数组的首地址, (*pc)[0]是数组的第一个元素, (*pc)[0](av, 3)是调用第一个函数f1

    // 用pd指针调用 f2, f3 函数
    const double *pdb = (*pd)[1](av, 3) ;   //  (*pd)[1](av, 3) === pa[1](av, 3) === f2(av, 3)
    cout << pdb << ": " << *pdb << endl;
    cout << (*pd)[2](av, 3) << ": " << *(*pd)[2](av, 3) << endl; // (*pd)[2](av, 3) === pa[2](av, 3) === f3(av, 3)
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;  // 不直接使用函数指针, 而是先取出函数指针的内容(把函数找到了), 再调用函数


    return 0;

}

const double * f1(const double* ar, int n)      // 输入数组指针, 返回double类型指针
{
    return ar;      // 返回数组第一个元素的地址
}

const double * f2(const double ar[], int n)
{
    return ar+1 ;       // 返回第二个元素的地址
};

const double * f3 (const double ar[], int n)
{
    return ar+2;        // 返回第三个元素的地址
}

