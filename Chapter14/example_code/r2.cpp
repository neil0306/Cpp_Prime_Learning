#include <cstring>
#include <iostream>

using namespace std;

class Frabjous
{
    private:
        char fab[20];
    public:
        Frabjous(const char *s = "C++")
        {
            strncpy(fab, s, 19);
            fab[19] = '\0';
        }
        virtual void tell() {cout << fab << endl;}

};

class Gloam
{
    private:
        int glip;
        Frabjous fb;
    public:
        Gloam(int g = 0, const char *s = "C++");
        Gloam(int g, const Frabjous &f);
        void tell();
};

Gloam::Gloam(int g, const char *s) : glip(g), fb(s)
{}

Gloam::Gloam(int g, const Frabjous &f): glip(g), fb(f)
{}

void Gloam::tell()
{
    cout << glip << endl;
    fb.tell();
}

int main(void)
{
    Gloam a(123, "Test C++");
    a.tell();
    return 0;
}