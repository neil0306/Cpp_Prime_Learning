#include <iostream>

int main(void)
{
    using namespace std;
    const int to_hour = 60*60, to_minute = 60, to_day = 60*60*24;
    long long second;
    
    cout << "Enter the number of seconds: ";
    cin >> second;
    // 计算这么多秒等于多少天, 多少小时, 多少分钟, 多少秒
    cout << second << " seconds = " << second / to_day << " days, " 
        << second % to_day / to_hour << " hours, " 
        << second % to_day % to_hour / to_minute << " minutes, " 
        << second % to_day % to_hour % to_minute << " seconds" 
        << endl;

    return 0;
}
