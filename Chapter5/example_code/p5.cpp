#include <iostream>
#include <string>

int main(void){
    using namespace std;

    // const string months[] = {"1","2","3","4","5","6","7","8","9","10","11","12"}; // 数组别忘了 [s]
    const string Month [] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

    int sale_num[12], sum = 0;

    for (int i = 0; i < 12; i++)
    {
        cout << "Enter the sale number of " << Month[i] << ": ";
        cin >> sale_num[i];
    }

    cout << "Input done.";


    for (int i = 0; i < 12; i++){
        sum += sale_num[i];
    }
    cout << "The total sale number is " << sum << endl;
    return 0;
}