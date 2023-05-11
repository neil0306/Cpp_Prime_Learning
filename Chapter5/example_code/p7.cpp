#include <iostream>
#include <string>
using namespace std;

struct car {
    string manufacture;   // 生产生
    int date;             // 生产日期

};          // 别忘记分号!!!


int main(void){

    int car_number;
    cout << "How many cars do you wish to catalog? ";
    (cin >> car_number).get();   // 记得用 get() 吃掉回车

    car * pcar = new car[car_number]; 

    for (int i = 0; i < car_number; i++){
        cout << "Car #" << i+1 << ": \n";
        cout << "Please enter the maker: ";
        getline(cin, (pcar+i)->manufacture);   // 指针名字在一定程度上可以和数组名互换使用
        cout << "Please enter the year made: ";
        (cin >> pcar[i].date).get();            // 记得吃掉数字后的回车
    }

    cout << "Here is your collection: \n";
    for (int i = 0; i < car_number; i++){
        cout << (pcar+i)->date << " " << (pcar+i)->manufacture << endl;
    }

    delete [] pcar;

    return 0;
}
