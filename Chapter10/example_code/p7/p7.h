#ifndef __P7_H__
#define __P7_H__

#include <iostream>
#include <cstring>

using namespace std;

class plorg
{
    private:
        static const int SIZE = 19;
        char name[SIZE];
        int CI;
    
    public:
        plorg(const char str[] = "Plorga", int ci = 50);
        void reset(int ci);
        void show() const;
};
#endif
