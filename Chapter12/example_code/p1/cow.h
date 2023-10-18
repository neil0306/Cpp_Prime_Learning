#ifndef __COW_H__
#define __COW_H__

#include <iostream>

using namespace std;

class Cow
{
    private:
        char name[20];
        char * hobby;
        double weight;
    public:
        Cow();
        Cow(const char * nm, const char * ho, double wt);
        Cow(const Cow &c);
        ~Cow();
        Cow & operator=(const Cow &c);
        void ShowCow() const;
};

#endif //!__COW_H__