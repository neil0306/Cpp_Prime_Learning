#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 20;

struct student 
{
    // 使用 char 数组进行存放
    char f_name[SIZE];          
    char l_name[SIZE];      
    char L_grade;  // leter grade

    int age;

};

int main(void)
{
    student s1;
    cout << "What is your first name? ";
    cin.getline(s1.f_name, SIZE);
    cout << "What is your last name? ";
    cin.getline(s1.l_name, SIZE);
    cout << "What letter grade do you deserve? ";
    cin >> s1.L_grade;
    cout << "What is you age? ";
    cin >> s1.age;

    cout << "Name: " << s1.l_name << ", " << s1.f_name << endl;  
    cout << "Grade: " <<  char (s1.L_grade + 1) << endl;
    cout << "Age: " << s1.age << endl; 

    return 0;
}