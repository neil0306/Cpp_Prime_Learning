#include <iostream>

using namespace std;

void countdown(int n);

int main(void)
{
    countdown(4);
    return 0;
}

void countdown(int n)
{
    // statement 1
    cout << "Counting down... | " << n << " (n at address: " << &n << ")" << endl;

    // 执行递归的条件
    if(n > 0){  
        countdown(n-1);
    } 

    // statement 2
    cout << n << ": kadoom" << "| (n at address: " << &n << ")" << endl;

}
