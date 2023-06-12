/*
    输入 xy 坐标, 输出极坐标
*/

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


void rect_to_polar(const rect *pxy, polar *pda);
void show_polar(const polar* dapos) ;

int main(void)
{
    rect rplace;
    polar pplace;
    cout << "Please the x and y values: ";

    while(cin >> rplace.x  >> rplace.y)  // 连续输入
    {
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);

        cout << "Next two nums (q to quit): ";
    }

    return 0;
}

void rect_to_polar(const rect *pxy, polar *pda)  // 不希望 pxy 被修改, 加const保护
{

    pda -> distance = sqrt(pxy->x * pxy->x  + pxy->x * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);    // atan2调库计算角度(弧度制), 本质上是一个反正切函数

}

void show_polar(const polar* dapos)   // distance angle position, 加 const 保护
{
    const double Rad_to_deg = 57.29577951;   // 单位转换
    cout << "Distance = " << dapos->distance << endl;
    cout << "Angle = " << dapos->angle * Rad_to_deg << " degrees." << endl;
}
