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
    
    CandyBar snack[3] = {{"test1", 1.11, 111},{"test2", 2.22, 222}, {"test3", 3.33, 333}};

    cout << "Brand: " << snack[0].brand << ", Weight: " << snack[0].weight << ", Calorie: " << snack[0].cal << endl;
    cout << "Brand: " << snack[1].brand << ", Weight: " << snack[1].weight << ", Calorie: " << snack[1].cal << endl;
    cout << "Brand: " << snack[2].brand << ", Weight: " << snack[2].weight << ", Calorie: " << snack[2].cal << endl;

    return 0;
}