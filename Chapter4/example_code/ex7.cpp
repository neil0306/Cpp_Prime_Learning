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
    pizza p1;
    
    cout << "Enter the enterprice name: ";
    getline(cin, p1.ent_name);
    cout << "Enter the diameter of the pizza: ";
    cin >> p1.diameter;
    cout << "Enter the weight of the pizza: ";
    cin >> p1.weight;
    
    cout << "Enterprice name: " << p1.ent_name << ", pizza diameter: " << p1.diameter << ", pizza weight: " << p1.weight << endl;

    return 0;
}