#include <iostream>
#include <string>

using namespace std;

struct pizza
{
    string ent_name;
    double diameter;
    double weight;
};

int main(void)
{
    pizza *pt = new pizza;


    cout << "Enter the weight of the pizza: ";
    cin >> (*pt).weight;
    cin.get();              // 清掉缓冲区里的换行符

    cout << "Enter the enterprice name: ";
    getline(cin, pt->ent_name);
    cout << "Enter the diameter of the pizza: ";
    cin >> (*pt).diameter;

    cout << "Enterprice name: " << pt->ent_name << ", pizza diameter: " << pt->diameter << ", pizza weight: " << pt->weight << endl;


    delete pt;
    return 0;
}