#include "classic.h"
#include <cstring>

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    strncpy(performers, s1, 50);
    if(strlen(s1) >= 50){
        performers[49] = '\0';
    }
    else{
        performers[strlen(s1)] = '\0';      // 由于strcpy不拷贝'\0', 所以当s1长度不及50时, 需要手动补一个'\0'
    }

    strncpy(label, s2, 20);
    if(strlen(s2) >= 20){
        label[19] = '\0';
    }
    else{
        label[strlen(s2)] = '\0';      // 由于strcpy不拷贝'\0', 所以当s2长度不及20时, 需要手动补一个'\0'
    }

    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
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

    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

Classic::Classic() : Cd()
{
    works[0] = '0';
}

Classic::Classic(const Classic &c) : Cd(c)
{
    strcpy(works, c.works);
}

Classic::Classic(const char *s1, const char *s2, const char *s3, int n, double x) : Cd(s2, s3, n, x)
{
    strncpy(works, s1, 50);
    if(strlen(s1) >= 50){
        works[49] = '\0';
    }
    else{
        works[strlen(s1)] = '\0';      // 由于strcpy不拷贝'\0', 所以当s1长度不及50时, 需要手动补一个'\0'
    }
}

void Classic::Report()
{
    Cd::Report();
    cout << "Works: " << works << endl;
}

Classic & Classic::operator=(const Classic &c)
{
    if(this == &c){
        return *this;
    }

    Cd::operator=(c); // 基类先拷贝一份
    strcpy(works, c.works);

    return *this;
}