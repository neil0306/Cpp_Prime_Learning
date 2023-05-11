#include <iostream>

const int DEPOSIT_BASE = 100;  // 初始存款是一样的

int main(void){
    
    using namespace std;

    double daphne_deposit = DEPOSIT_BASE;
    double Cleo_deposit = DEPOSIT_BASE;

    int year = 0;

    while (daphne_deposit >= Cleo_deposit){
        daphne_deposit += 10;
        Cleo_deposit += Cleo_deposit * 0.05;
        year++; 
    }

    cout << "After " << year << " years, Cleo's has more money than daphne.\n";

    cout << "Daphne has " << daphne_deposit << " dollars deposit.\n";
    cout << "Cleo has " << Cleo_deposit << " dollars deposit.\n";
    return 0;
}