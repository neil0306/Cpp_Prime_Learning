#include <iostream>
#include "studentc.h"

using namespace std;

const int pupils = 3;
const int quizzes =5;

void set(Student &sa, int n);

int main(void)
{
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
    int i = 0;;

    // 录入信息
    for (i = 0; i < pupils; i++){
        set(ada[i], quizzes);       // 这里的 ada[i] 访问的是 "不同的Student对象"
    }
    cout << " -------- " << endl;

    // 输出
    cout << "Student List: " << endl;
    for (i = 0; i < pupils; i++){
        cout << ada[i].Name() << endl;
    }
    cout << " -------- " << endl;

    cout << "Result List: " << endl;
    for (i = 0; i < pupils; i++){
        cout << ada[i];             // 使用友元函数 operator<<()
        cout << "Average: " << ada[i].Average() << endl;
    }

    return 0;
}

void set(Student &sa, int n)
{
    cout << "Please enter the student's name: " << endl;
    getline(cin, sa);
    cout << "Please enter " << n << " quizzes scores: " << endl;
    for (int i = 0; i < n; i++){
        cin >> sa[i];           // 这里的 sa[i] 访问的是 Student对象里的[]重载运算符, 填充的是对象里面的 scores 数组
    }

    // 每当输入数字之后, 缓冲区都会存在一个多余的回车, 记得干掉.
    while(cin.get() != '\n');
}