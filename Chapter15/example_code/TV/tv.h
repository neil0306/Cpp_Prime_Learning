#ifndef __TV_H__
#define __TV_H__

#include <iostream>

using namespace std;

class Tv
{
    private:
        enum {off, on};
        enum {MinVol = 0, MaxVol = 20};
        enum {MinChan = 1, MaxChan = 100};
        enum {TV, DVD};

        int state;      // 表示電視的狀態: 0打開, 1關閉
        int volume;     // 音量
        int channel;    // 頻道
        int input;      // 輸入方式: TV, DVD

    public:
        Tv(int s = off) : state(s), volume(5), channel(2), input(TV){}
        void onoff(){ state = (state == on ? off : on);}       // 切換電視開關
        bool volup();    // 音量增
        bool voldown();  // 音量減  
        void chanup();       // 頻道增
        void chandown();     // 頻道減
        void setInput() {input = (input == TV ? DVD : TV);}     // 修改輸入方式(信號源)
        void showSettings() const;

        friend class Remote;        // 友元類
};


// 遙控器類 應該成為 電視機類 的友元類, 因為從邏輯上講, 遙控器和電視機之間沒有繼承關係, 也不應該是包含關係
class Remote
{
    private:
        int mode;
    public:
        Remote(int m = Tv::TV) : mode(m){}     // 因為是友元關係, 允許使用另一個類的私有枚舉

        // 操作輸入的Tv類對象(遙控器控制某個電視)
        void onoff(Tv &t) {t.onoff();}; 
        bool volup(Tv &t){ return t.volup();}
        bool voldown(Tv &t){ return t.voldown();}
        void chanup(Tv &t){t.chanup();}
        void chandonw(Tv &t){t.chandown();}
        void setChannel(Tv &t, int c){t.channel = c;}   // 直接訪問了私有成員, 並賦值!
        void setInput(Tv &t) {t.setInput();}
};

#endif //!__TV_H__
