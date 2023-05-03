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
    
    CandyBar snack = {"Mocha Munch", 2.3, 350};

    cout << "Brand: " << snack.brand << ", Weight: " << snack.weight << ", Calorie: " << snack.cal << endl;

    return 0;
}