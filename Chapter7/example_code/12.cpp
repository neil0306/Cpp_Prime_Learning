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


polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main(void)
{
    rect rplace;
    polar pplace;
    cout << "Please the x and y values: ";

    while(cin >> rplace.x  >> rplace.y)  // 连续输入
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);

        cout << "Next two nums (q to quit): ";
    }

    return 0;
}

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
