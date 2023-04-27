#include <iostream>

int main(void)
{
    using namespace std;
    const double to_inch = 12;
    const double to_meter = 0.0254;
    const double to_kg = 2.2;

    double h_inch;
    double h_feet;
    double w_pounds;

    cout << "Please enter your height in feet and inches: ";
    cin >> h_inch >> h_feet;      // cin不换行接收多个变量的数据, 输入数据时, 中间用空格隔开, 空格会被识别为结束符.

    cout << "Please enter your weight in pounds: _\b";
    cin >> w_pounds;

    double h_meter = (h_feet * to_inch + h_inch) * to_meter;
    double w_kg = w_pounds / to_kg;
    // cout << "h_meter = " << h_meter << ", w_kg = " << w_kg << endl;
    cout << "Your BMI is " << w_kg / (h_meter * h_meter) << endl;

    return 0;
}