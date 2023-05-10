#include <iostream>

const int ArrSize = 16;

int main(void){
    long long factorials[ArrSize];

    factorials[0] = factorials[1] = 1LL;  // long long 类型

    for (int i=2; i<ArrSize; i++){
        factorials[i] = i * factorials[i-1];
    }

    for (int i =0; i < ArrSize; i ++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    return 0;
}