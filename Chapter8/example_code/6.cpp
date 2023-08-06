#include <iostream>
#include <string>
using namespace std;

struct free_throws
{
    string name;
    int made;
    int attemps;
    float percent;
};

void set_pc (free_throws & ft);
void display(const free_throws & ft);        // 显示的时候不应该修改任何东西, 加 const
// 注意: 这里的 accumulate 返回的是一个引用, 这样才能实现链式赋值
free_throws & accumulate(free_throws & target, free_throws & src);

int main(void)
{
    // percet 默认为0
    free_throws one = {"Rick", 13, 14};
    free_throws two = {"Jack", 10, 16};
    free_throws three = {"Jerry", 7,9 };
    free_throws four = {"Jason", 8, 11};
    free_throws five = {"Michael", 5, 14};
    free_throws team = {"Class 6", 0, 0};

    // 用函数填充percent, 再显示
    set_pc(one);
    display(one);

    // 累加并显示
    accumulate(team, one);
    display(team);

    display(accumulate(team, two));


    // 链式赋值
    accumulate(accumulate(accumulate(team, three), four), five);
    /*
    等价于:
        // accumulate(team, three);
        // accumulate(team, four);
        // accumulate(team, five);
    */
    display(team);

    return 0;
}

void set_pc (free_throws & ft)
{
    if (ft.attemps != 0){
        ft.percent = 100 * static_cast<float>(ft.made) / static_cast<float>(ft.attemps);
    }
    else{
        ft.percent = 0;
    }
}

void display(const free_throws & ft)        // 显示的时候不应该修改任何东西, 加 const
{
    cout << "Name: " << ft.name << endl;
    cout << "Made: " << ft.made << "\t";
    cout << "Attemps: " << ft.attemps << "\t";
    cout << "Percent: " << ft.percent << endl;
}

free_throws & accumulate(free_throws & target, free_throws & src)
{
    target.attemps += src.attemps;
    target.made += src.made;
    set_pc(target);
    return target;
}
