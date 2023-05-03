#include <iostream>
#include <string>

using namespace std;
struct CandyBar
{
    string brand;
    double weight;
    int cal;
};

int main(void)
{
    
    // CandyBar snack[3] = {{"test1", 1.11, 111},{"test2", 2.22, 222}, {"test3", 3.33, 333}};
    CandyBar *pt = new CandyBar [3];        // new 了一个动态数组, 然后把地址赋给 pt 指针.

    pt[0].brand = "test1";
    pt[1].brand = "test2";
    pt[2].brand = "test3"; // 其他成员没有赋值, 数值成员默认为0, 字符成员默认为空字符 
    
    cout << "Brand: " << pt[0].brand << ", Weight: " << pt[0].weight << ", Calorie: " << pt[0].cal << endl;
    cout << "Brand: " << pt[1].brand << ", Weight: " << pt[1].weight << ", Calorie: " << pt[1].cal << endl;
    cout << "Brand: " << pt[2].brand << ", Weight: " << pt[2].weight << ", Calorie: " << pt[2].cal << endl;

    delete [] pt;   // 千万别忘记释放内存!!!
    return 0;
}