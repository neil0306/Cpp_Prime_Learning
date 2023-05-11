#include <iostream>

int main(void){
    using namespace std;

    
    double num = 0, sum = 0;

    do {
        cout << "Please enter a number: ";
        cin >> num;
        sum += num;
        
    }
    while (num != 0);       // while 后面别忘了加分号！！
    
    cout << "The sum of previous num is: " << sum << endl;
    return 0;
}