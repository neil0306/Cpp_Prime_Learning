#include <iostream>
#include <string>

using namespace std;

struct patrons
{
    string name;
    double donation;
};


int main(void)
{
    int numbers;
    bool emp_flag = true;

    patrons* ppatrons = new patrons [numbers];  // 动态结构体数组

    cout << "Enter the number of donors: ";
    cin >> numbers;


    for (int i = 0; i < numbers; i++)
    {
        cout << "donor #" << i+1 << ": \n";
        cout << "Enter the name of donor: ";
        cin >> ppatrons[i].name;                // string 类型可以直接 cin >>

        cout << "Enter the donation amount: ";
        cin >> ppatrons[i].donation;
    }

    cout << "\n----- Grand Patrons -----\n";
    for (int i = 0; i < numbers; i++)
    {
        if (ppatrons[i].donation >= 10000)
        {
            emp_flag = false;       // 数组中有记录, 非空
            cout << ppatrons[i].name << ": " << ppatrons[i].donation << endl;
        }
    }
    if (emp_flag)
        cout << "None" << endl;   // 如果没有这类人, 就直接打印 none

    emp_flag = true;   // re-init
    cout << "\n----- Patrons -----\n";
    for (int i = 0; i < numbers; i++)
    {
        if (ppatrons[i].donation < 10000)
        {
            emp_flag = false; 
            cout << ppatrons[i].name << ": " << ppatrons[i].donation << endl;
        }
    }

    if (emp_flag)
        cout << "None" << endl;   // 如果没有这类人, 就直接打印 none

    return 0;
}