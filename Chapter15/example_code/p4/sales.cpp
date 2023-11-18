#include "sales.h"

Sales::Sales(int yy)
{
    year = yy;
    for (int i = 0; i < MONTHS; i++){
        gross[i] = 0;
    }
}

Sales::Sales(int yy, const double * gr, int n)
{
    year = yy;
    int lim = n < MONTHS ? n : MONTHS;  // 限制不超過12
    int i;
    for (i = 0; i < lim; i++){
        gross[i] = gr[i];
    }
    for (; i < MONTHS; i++){
        gross[i] = 0;
    }
}

double Sales::operator[](int i) const
{
    if( i < 0 || i > MONTHS){
        throw bad_index(i);     // 拋出異常, 使用的是嵌套在內部的異常類
    }
    return gross[i];
}

double & Sales::operator[](int i)
{
    if( i < 0 || i > MONTHS){
        throw bad_index(i);     // 拋出異常, 使用的是嵌套在內部的異常類
    }
    return gross[i];
}

double LabelSales::operator[](int i) const
{
    if( i < 0 || i > MONTHS){
        throw nbad_index(Label(), i);     // 拋出異常, 使用的是嵌套在內部的異常類
    }
    return Sales::operator[](i);    // 注意, 由於 gross 這個數組是 Sale 私有的, 所以只能調用成員函數進行訪問
}

double & LabelSales::operator[](int i) 
{
    if( i < 0 || i > MONTHS){
        throw nbad_index(Label(), i);     // 拋出異常, 使用的是嵌套在內部的異常類
    }
    return Sales::operator[](i);     // 注意, 由於 gross 這個數組是 Sale 私有的, 所以只能調用成員函數進行訪問
}

