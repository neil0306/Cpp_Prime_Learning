#include <iostream>

using namespace std;

int main(void)
{
    cout << "Enter Numbers: " << endl;
    int sum = 0;
    int input;
    while(cin >> input){
        sum += input;
    }
    cout << "Sum = " << sum << endl;
    cout << "Last value entered: " << input << endl;
    return 0;
}