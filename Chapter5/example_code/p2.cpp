#include <iostream>
#include <array>

const int ArrSize = 16;

int main(void){
    using namespace std;
    // long long factorials[ArrSize];   // 原来的代码
    array<long long, ArrSize> factorials;

    factorials[0] = factorials[1] = 1LL;  // long long 类型

    for (int i=2; i<ArrSize; i++){
        factorials[i] = i * factorials[i-1];
    }

    for (int i =0; i < ArrSize; i ++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    return 0;
}