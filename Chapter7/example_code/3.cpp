#include <iostream>

using namespace std;
void n_chars (char c, int n);

int main(void)
{
    char ch;
    int n;

    cout << "Enter a character: ";
    cin >> ch;  // 这里不要用 cin.get() 因为我们不需要捕获回车

    while (ch != 'q')
    {
        cout << "Enter an integer: ";
        cin >> n;
        n_chars(ch, n);
        // cout << "The value of n is " << n << ".\n";  // 观察形参 n 的值是否改变
        cout << endl;
        cout << "Enter another character or press the q-key to quit: ";
        cin >> ch;
    }
    

    return 0;
}

void n_chars(char c, int n)
{
    while (n-- > 0)
        cout << c;
}