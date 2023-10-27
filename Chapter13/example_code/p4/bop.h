#ifndef __BOP_H__
#define __BOP_H__

#include <iostream>

using namespace std;

class Port
{
    private:
        char * brand;
        char style[20];
        int bottles;
    public:
        Port(const char * br = "none", const char * st = "none", int b = 0);
        Port(const Port &p);
        virtual ~Port(){ delete [] brand; }
        Port & operator=(const Port &p);
        Port & operator+=(int b);
        Port & operator-=(int b);
        int BottleCount() const {return bottles;}
        virtual void Show() const;
        friend ostream & operator<<(ostream &os, const Port &p);
};

class VintagePort :  public Port
{
    private: 
        char * nickname;
        int year;
    public:
        VintagePort();
        VintagePort(const char * br, const char * st, int b, const char * nn, int y);
        VintagePort(const VintagePort &vp);
        ~VintagePort() {delete [] nickname; }
        VintagePort & operator=(const VintagePort &vp);
        void Show() const;
        friend ostream & operator<<(ostream &os, const VintagePort &vp);
};

#endif //!__BOP_H__
