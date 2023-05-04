#include <iostream>

int main(void)
{
    using namespace std;

    cout << "Enter the starting countdown value: ";
    int limit ;
    cin >> limit;

    int i;
    for(i=limit; i; i--)
        cout << "i = " << i << endl;

    cout << "Done, now that i = " << i << endl;  // 最后打印一下 i, i此时肯定是0, 因为0对应的bool类型是 false

    return 0;
}