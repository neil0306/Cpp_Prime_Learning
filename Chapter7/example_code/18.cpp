#include <iostream>

using namespace std;

double Rick(int lines);
double Jack(int lines);
void estimate(int lines, double (*pf)(int));

int main(void)
{
    int code;

    cout << "How many lines of codes do you need? ";
    cin >> code;

    cout << "Here is Rick's estimate: " << endl;
    estimate(code, Rick);   // Rick 是一个函数名

    cout << "Here is Jack's estimate: " << endl;
    estimate(code, Jack);   // Jack 是一个函数名

    return 0;
}

double Rick(int lines)
{
    return lines * 0.05;
}

double Jack(int lines)
{
    return lines * 0.03 + 0.0004 * lines * lines;
}

void estimate(int lines, double (*pf)(int))
{
    cout << lines << " lines code will task " << (*pf)(lines) << " hours to complete." << endl;
}