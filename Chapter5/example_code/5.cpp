#include <iostream>

int main(void){
    using std::cout;
    using std::endl;
    using std::cin;

    cout << "Enter an integer: ";
    int by;
    cin >> by;

    cout << "Counting by " << by << "\n";

    for (int i = 0; i < 100; i = i + by){
        cout << i << endl;
    }
}