#include <iostream>

using namespace std;

struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void setBox(box *pb);
void showBox(box a);

int main(void)
{
    box b = {"cube", 3, 4, 5};      // 没有填入volume

    setBox(&b);     // 传地址

    showBox(b);     // 传值

    return 0;
}

void setBox(box *pb)
{
    pb->volume = pb->height*pb->length*pb->width;
}

void showBox(box a)
{
    cout << "Maker: " << a.maker << endl;
    cout << "Height: " << a.height << endl;
    cout << "Width: " << a.width << endl;
    cout << "Length: " << a.length << endl;
    cout << "Volume: " << a.volume << endl;
}