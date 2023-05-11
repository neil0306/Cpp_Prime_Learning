#include <iostream>
using namespace std;

int main(void){
    int row;
    cout << "Please enter the number of rows: ";
    cin >> row;

    // 按行打印
    for (int i = 0; i < row; i++){
        // 打印点
        for(int j = 0; j < row - i -1; j++){
            cout << ". ";
        }
        for (int j = 0; j <= i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}