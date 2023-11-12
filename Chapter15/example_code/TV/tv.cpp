#include "tv.h"

bool Tv::volup()
{
    if(volume < MaxVol){
        volume ++;
        return true;
    }
    else{
        return false;
    }
}

bool Tv::voldown()
{
    if(volume > MinVol){
        volume ++;
        return true;
    }
    else{
        return false;
    }
}

void Tv::chanup()
{
    if(channel < MaxChan){
        channel++;
    }
    else{
        channel = MinChan;        // 達到最大頻道時, 回到最小頻道即可
    }
}

void Tv::chandown()
{
    if(channel > MinChan){
        channel --;
    }
    else{
        channel = MaxChan;        // 達到最小頻道時, 回到最大頻道即可
    }
}

void Tv::showSettings() const
{
    cout << "TV is " << (state == off ? "off" : "on") << endl;
    if (state == on){
        cout << "Volume = " << volume << endl;
        cout << "Channel = " << channel << endl;
        cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
    }
}

