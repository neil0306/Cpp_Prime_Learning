#include "classic.h"
#include <cstring>

// 基类
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);

    label = new char[strlen(s2) + 1];
    strcpy(label, s1);

    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    performers = new char[strlen(d.performers) +1];
    strcpy(performers, d.performers);

    label = new char[strlen(d.label) +1];
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const
{
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd &d)
{
    if (this == &d){
        return *this;
    }

    delete [] performers;
    delete [] label;

    performers = new char[strlen(d.performers) +1];
    label = new char[strlen(d.label) +1];

    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

// 派生类
Classic::Classic() : Cd()
{
    works = nullptr;
}

Classic::Classic(const Classic &c) : Cd(c)
{
    works = new char[strlen(c.works) +1];
    strcpy(works, c.works);
}

Classic::Classic(const char *s1, const char *s2, const char *s3, int n, double x) : Cd(s2, s3, n, x)
{
    works = new char[strlen(s1) +1];
    strcpy(works, s1);
}

Classic::~Classic()
{
    delete [] works;
}

void Classic::Report()
{
    Cd::Report();
    cout << "Works: " << works << endl;
}

// PDF的 518页 有例题
Classic & Classic::operator=(const Classic &c)
{
    // step1:
    if(this == &c){
        return *this;
    }

    // step2: 调用基类的赋值运算符, 完成基类的赋值
    Cd::operator=(c);

    // step3:
    delete [] works;

    // Step4:
    works = new char[strlen(c.works) +1];

    // step5:
    strcpy(works, c.works);

    return *this;
}