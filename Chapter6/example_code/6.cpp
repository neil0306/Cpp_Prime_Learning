#include <iostream>
using namespace std;
const char * qualify[] = {      // 字符串数组, 用指针作为数组名
    "perfect",
    "great",
    "good",
    "just so so",
    "failed"
};

int main(void)
{
    int score, index;

    cout << "Enter your scores: ";
    cin >> score;

    if (score >= 90 && score <= 100)
        index = 0;
    else if (score >= 80 && score <= 89)
        index = 1;
    else if (score >= 70 && score <= 79)
        index = 2;
    else if (score >= 60 && score <= 69)
        index = 3;
    else
        index = 4;
    
    cout << "Your level is " << qualify[index] << "\n";
    return 0;
}