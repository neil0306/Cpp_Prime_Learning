#include <iostream>

using namespace std;

const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

// getinfo() 从标准输入中读取 n 个学生的信息, 并保存到结构数组中
// 返回值是实际读取的学生个数
int getinfo(student pa[], int n);

// display1() 显示一个学生的信息
void display1(student st);

// display2() 显示结构数组中的所有学生信息
void display2(const student pa[], int n);

// display3() 显示结构数组中的所有学生信息
// 但是使用指向结构的指针
void display3(const student* ps, int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n'){
        continue;
    }

    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i], 1);
    }

    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";
    return 0;
}


int getinfo(student pa[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        cout << "Enter the name of student #" << i+1 << ": ";
        cin >> pa[i].fullname;

        cout << "Enter the hoby of student #" << i+1 << ": ";
        cin >> pa[i].hobby;

        cout << "Enter the level of student #" << i+1 << ": ";
        cin >> pa[i].ooplevel;
        
        if (!cin){
            cin.clear();
            while(cin.get() != '\n');
            break;
        }
    }
    return i;
}

void display1(student st)
{
    // 结构体支持直接对拷(注意 数组不支持对拷)
    cout << "Name: " << st.fullname << endl;
    cout << "Hoby: " << st.hobby << endl;
    cout << "Level: " << st.ooplevel << endl;
    cout << endl;
}

void display2(const student pa[], int n)
{
    for (int i = 0; i < n; i++){
        cout << "Student #" << i+1 << endl;
        cout << "Name: " << pa[i].fullname << endl;
        cout << "Hoby: " << pa[i].hobby << endl;
        cout << "Level: " << pa[i].ooplevel << endl;
        cout << endl;
    }
}

void display3(const student* ps, int n)
{
    for (int i = 0; i < n; i++){
        cout << "Student #" << i+1 << endl;
        cout << "Name: " << ps[i].fullname << endl;
        cout << "Hoby: " << ps[i].hobby << endl;
        cout << "Level: " << ps[i].ooplevel << endl;
        cout << endl;
    }
}
