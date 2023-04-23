#include <iostream>
using namespace std;

int main(void)
{
    int age;
    cout << "Enter you age: ";
    
    cin >> age;

    cout << "Your age in months is " << age * 12 << "." << endl;

    return 0;
}