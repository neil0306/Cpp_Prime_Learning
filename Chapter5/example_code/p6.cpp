#include <iostream>
#include <string>

int main(void){

    using namespace std;

    const string Month [] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int sale_num[3][12], sum = 0;

    for (int i = 0; i < 3; i++){

        cout << "Starting " << i+1 << " year's data" << endl;
        for (int j = 0; j < 12; j++){
            cout << "Enter the sale number of " << Month[j] << ": ";
            cin >> sale_num[i][j];
        }
    }
    cout << "Input Done! \n";

    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 12; j++){
            sum += sale_num[i][j];
        }
    }
    cout << "Total number of sale books for 3 years is " << sum << endl; 

    return 0;
}