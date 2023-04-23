#include <iostream>
using namespace std;

void my_func_1(void);
void my_func_2(void);

int main(void)
{
    my_func_1();
    my_func_1();
    my_func_2();
    my_func_2();

    return 0;
}

void my_func_1(void)
{
    cout << "Three blind mice" << endl;
}

void my_func_2(void)
{
    cout << "See how they run" << endl;
}