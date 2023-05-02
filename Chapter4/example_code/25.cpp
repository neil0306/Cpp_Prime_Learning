# include <iostream>

using namespace std;

struct antactica_years_end
{
    int year;
};

int main(void)
{
    antactica_years_end s01, s02, s03;
    s01.year = 1998;

    antactica_years_end *pa = &s02;
    pa->year = 1999;

    antactica_years_end trio[3];        // 数组的每一个元素都是一个结构体类型
    trio[0].year = 2003;                // trio[0]是一个结构体对象
    cout << trio -> year << endl;


    const antactica_years_end *arp[3] = {&s01, &s02, &s03};   // 结构体数组, 元素都是指针(结构体类型的指针)

    cout << arp[1] -> year << endl;     // s02 的成员 year


    // 指针的指针

    const antactica_years_end **ppa = arp;   // 指向指针的指针, 它也是一个地址
    cout << (*ppa) -> year << endl;         // s01 的成员 year, 应打印1998

    // C++ 11 中才支持的特性
    auto ppb = arp;                         // 使用 auto 关键字自动决定类型, 此时 ppb 就是 arp 数组, 它也是一个结构体指针数组

    cout << (*(ppb + 1)) -> year << endl;   // (ppb +1) == (arp +1) == arp[1], 都是arp数组的第二个元素的首地址
                                            //  (*(ppb +1)) == &s02, 都是指向 s02 的地址, 故需访问成员需要使用 -> 
                                            // 应打印1999

    return 0;
}